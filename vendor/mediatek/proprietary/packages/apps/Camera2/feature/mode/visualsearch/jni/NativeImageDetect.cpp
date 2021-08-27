#include <vector>
#include "com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect.h"

#include "ImageNeurPilot.h"
#include "CipherUtils.h"

#define LOG_TAG "JNI_NativeImageDetect"
ImageNeurPilot *imageNeurPilot;
CipherUtils *mCipherUtils;

static const char key[] = {'M', 'T', 'K'};

extern "C" {

JNIEXPORT void JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_init(JNIEnv *env,
                                                                                jclass clazz) {
    if (imageNeurPilot == nullptr) {
        imageNeurPilot = new ImageNeurPilot();
    }

    if (mCipherUtils == nullptr) {
        mCipherUtils = new CipherUtils();
    }
}

JNIEXPORT jint JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_initModel(
    JNIEnv *env, jclass clazz, jint model_type, jstring model_path, jstring label_path, jint detect_count) {
    char *model_path_ = jStringToChar(env, model_path);
    char *label_path_ = jStringToChar(env, label_path);
    if (model_path_ == nullptr || label_path_ == nullptr) {
        if (model_path_ != nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "label_path_ is null");
            free(model_path_);
        }

        if (label_path_ != nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "model_path_ is null");
            free(label_path_);
        }
        return 0;
    }
    int ret = 0;
    if (imageNeurPilot != nullptr) {
        ret = imageNeurPilot->init(static_cast<uint32_t>(model_type),
                                   model_path_, label_path_, detect_count);
    }
    if (ret == 0) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "initModel failed");
    }

    free(model_path_);
    free(label_path_);
    return ret;

}

JNIEXPORT jint JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_initModelsByPath(
        JNIEnv *env, jclass clazz, jint model_type, jstring model_path, jobject label_list, jint detect_count) {

    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "initModelsByPath start");
    jint ret = 0;
    char *iBuf = nullptr;
    size_t length = 0;

    std::vector<std::string> labels;

    jclass jcs_alist = env->FindClass("java/util/ArrayList");
    jmethodID alist_get = env->GetMethodID(jcs_alist, "get",
                                           "(I)Ljava/lang/Object;");
    jmethodID alist_size = env->GetMethodID(jcs_alist, "size", "()I");
    jint len = env->CallIntMethod(label_list, alist_size);

    for (int i = 0; i < len; i++) {
        jstring strObj = (jstring) env->CallObjectMethod(label_list, alist_get, i);
        if (strObj == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,
                            "init model failed ,label_list is null.");
            return 0;
        }
        const char *chr = env->GetStringUTFChars(strObj, JNI_FALSE);
        if (chr == nullptr) {
            __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,
                            "init model failed ,string to char failed.");
            return 0;
        }
        labels.insert(labels.end(), chr);
        env->ReleaseStringUTFChars(strObj, chr);
    }

    char *modelPath = (char *) env->GetStringUTFChars(model_path, 0);

    FILE *fd = fopen(modelPath, "rwe");
    if (fd == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,
                            "Failed to open the  %s model_data file descriptor.", modelPath);
        return 0;
    }
    int seek_ret = fseek(fd, 0L, SEEK_END);
    length = ftell(fd);
    if (length < 0 || seek_ret < 0) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,
                            "file open failed length =%zu,seek_ret = %d",length,seek_ret);
        fclose(fd);
        return 0;
    }
    seek_ret = fseek(fd, 0L, SEEK_SET);
    iBuf = (char *) malloc(length);

    if (!iBuf || seek_ret < 0) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,
                            "iBuf memony malloc failed, seek_ret = %d",seek_ret);
        free(iBuf);
        fclose(fd);
        return 0;
    }
    size_t readSize = fread(iBuf, sizeof(char), length, fd);
    fclose(fd);
    if (readSize != length) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,
                            "readSize:%zu != length: %zu ",readSize,length);
        free(iBuf);
        return 0;
    }
    std::string hashed_str = std::string(key);
    auto hashed_str_len = hashed_str.length();
    char real_key[hashed_str_len];
    hashed_str.copy(real_key, hashed_str_len);

    // Decrypt the model with hashed key
    for (size_t i = 0; i < length; i++) {
        iBuf[i] ^= real_key[i % hashed_str_len];
    }
    if (imageNeurPilot != nullptr) {
        ret = imageNeurPilot->init(static_cast<uint32_t>(model_type),
                               iBuf, (size_t) length, labels, detect_count);
    }
    if (ret == 0) {
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "initModel failed");
    }
    free(iBuf);
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "initModelsByPath end");
    return ret;

}

JNIEXPORT jint JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_initModels
        (JNIEnv *env, jclass clazz, jint model_type, jobject asset_manager, jstring model_name,
         jobject label_list, jint detect_count) {
    jint ret = 0;
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "initModels start");

    std::vector<std::string> labels;

    jclass jcs_alist = env->FindClass("java/util/ArrayList");
    jmethodID alist_get = env->GetMethodID(jcs_alist, "get",
                                           "(I)Ljava/lang/Object;");
    jmethodID alist_size = env->GetMethodID(jcs_alist, "size", "()I");
    jint len = env->CallIntMethod(label_list, alist_size);

    for (int i = 0; i < len; i++) {
        jstring strObj = (jstring) env->CallObjectMethod(label_list, alist_get, i);
        if (strObj == nullptr) {
            return 0;
        }
        const char *chr = env->GetStringUTFChars(strObj, JNI_FALSE);
        if (chr == nullptr) {
            return 0;
        }
        labels.insert(labels.end(), chr);
        env->ReleaseStringUTFChars(strObj, chr);
    }

    AAssetManager *assetManager = AAssetManager_fromJava(env, asset_manager);
    const char *assetName = env->GetStringUTFChars(model_name, nullptr);
    AAsset *asset = AAssetManager_open(assetManager, assetName, AASSET_MODE_BUFFER);
    if (asset == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "Failed to open the asset.");
        return 0;
    }
    env->ReleaseStringUTFChars(model_name, assetName);
    off_t offset, length;
    int fd = AAsset_openFileDescriptor(asset, &offset, &length);
    AAsset_close(asset);
    if (fd < 0) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG,
                            "Failed to open the model_data file descriptor.");
        return 0;
    }
    lseek(fd, offset, SEEK_CUR); //NOTICE
    char *dataBuffer = (char *) malloc((size_t) length);
    if (!dataBuffer) {
        free(dataBuffer);
        close(fd);
        return 0;
    }
    read(fd, dataBuffer, (size_t) length);

    std::string hashed_str = std::string(key);
    auto hashed_str_len = hashed_str.length();
    char real_key[hashed_str_len];
    hashed_str.copy(real_key, hashed_str_len);

    // Decrypt the model with hashed key
    for (size_t i = 0; i < length; i++) {
        dataBuffer[i] ^= real_key[i % hashed_str_len];
    }
    close(fd);
    if (imageNeurPilot != nullptr) {
        ret = imageNeurPilot->init(static_cast<uint32_t>(model_type),
                               dataBuffer, (size_t) length, labels, detect_count);
    }
    if (ret == 0) {
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "initModel failed");
    }
    free(dataBuffer);
    return ret;
}

JNIEXPORT jint JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_initModelList(
        JNIEnv *env, jclass clazz, jint model_type, jobject label_list, jint detect_count) {
    std::vector<std::string> labels_vector;

    jclass jcs_alist = env->FindClass("java/util/ArrayList");
    jmethodID alist_get = env->GetMethodID(jcs_alist, "get",
                                           "(I)Ljava/lang/Object;");
    jmethodID alist_size = env->GetMethodID(jcs_alist, "size", "()I");
    jint len = env->CallIntMethod(label_list, alist_size);

    for (int i = 0; i < len; i++) {
        jstring strObj = (jstring) env->CallObjectMethod(label_list, alist_get, i);
        const char *chr = env->GetStringUTFChars(strObj, JNI_FALSE);
        labels_vector.insert(labels_vector.end(), chr);
        env->ReleaseStringUTFChars(strObj, chr);
    }
    int ret =0;
    if (imageNeurPilot != nullptr) {
        ret = imageNeurPilot->init(static_cast<uint32_t>(model_type), labels_vector, detect_count);
    }
    if (ret == 0) {
        __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "initModel failed");
    }
    return ret;
}

char *jStringToChar(JNIEnv *env, jstring jstr) {
    char *rtn = nullptr;
    jclass clsstring = (env)->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("utf-8");
    jmethodID mid = env->GetMethodID(clsstring, "getBytes",
                                     "(Ljava/lang/String;)[B");
    jbyteArray barr = (jbyteArray) env->CallObjectMethod(jstr, mid, strencode);
    jsize alen = env->GetArrayLength(barr);
    jbyte *ba = env->GetByteArrayElements(barr, JNI_FALSE);
    if (alen > 0) {
        rtn = (char *) malloc(static_cast<size_t>(alen + 1));
        if (!rtn || ba == nullptr) {
            free(rtn);
            return nullptr;
        }
        memcpy(rtn, ba, static_cast<size_t>(alen));
        rtn[alen] = 0;
    }
    env->ReleaseByteArrayElements(barr, ba, 0);
    return rtn;
}

JNIEXPORT jstring JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_compute(JNIEnv *env,
                                                                                   jclass clazz,
                                                                                   jobject imageByteBuffer,
                                                                                   jlong imageByteBufferSize,
                                                                                   jint model_type) {
    unsigned char *productList = nullptr;

    uint8_t *bufferAddr = (uint8_t *) env->GetDirectBufferAddress(imageByteBuffer);

    if (imageNeurPilot != nullptr) {
        productList = imageNeurPilot->run_inference(bufferAddr, (size_t) imageByteBufferSize,
                                                static_cast<uint32_t>(model_type));
    }
    if (productList == nullptr) {
        __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, "not productList");
        return nullptr;

    }
    const char *product = (const char *) productList;
    jsize len = static_cast<jsize>(strlen(product));
    if (len < 0) {
        return nullptr;
    }
    jclass clsstring = env->FindClass("java/lang/String");
    jstring strencode = env->NewStringUTF("UTF-8");
    jmethodID mid = env->GetMethodID(clsstring, "<init>",
                                     "([BLjava/lang/String;)V");
    jbyteArray barr = env->NewByteArray(len);
    env->SetByteArrayRegion(barr, 0, len, (jbyte *) product);
    return (jstring) env->NewObject(clsstring, mid, barr, strencode);
}

JNIEXPORT jbyteArray JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_encodeRSAPrivateKey(
        JNIEnv *env, jclass clazz, jbyteArray src_) {
    jbyte *src = env->GetByteArrayElements(src_, nullptr);
    jsize src_Len = env->GetArrayLength(src_);
    jint plaintext_offset = 0;
    unsigned char *desText = nullptr;
    if (mCipherUtils != nullptr) {
        desText = mCipherUtils->encodeRSAPrivateKey(reinterpret_cast<const char *>(src),
            static_cast<uint32_t>(src_Len),reinterpret_cast<uint32_t &>(plaintext_offset));
    }
    jbyteArray clear = env->NewByteArray(plaintext_offset);
    env->SetByteArrayRegion(clear, 0, plaintext_offset, (jbyte *) desText);

    return clear;
}

JNIEXPORT jbyteArray JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_decodeRSAPubKey(
        JNIEnv *env, jclass clazz, jbyteArray src_) {
    jbyte *src = env->GetByteArrayElements(src_, nullptr);
    jsize src_Len = env->GetArrayLength(src_);
    jint plaintext_offset = 0;
    unsigned char *desText = nullptr;
    if (mCipherUtils != nullptr) {
        desText = mCipherUtils->decodeRSAPublicKey(reinterpret_cast<const char *>(src),
            static_cast<uint32_t>(src_Len),reinterpret_cast<uint32_t &>(plaintext_offset));
    }
    jbyteArray cipher = env->NewByteArray(plaintext_offset);
    env->SetByteArrayRegion(cipher, 0, plaintext_offset, (jbyte *) desText);

    return cipher;
}


JNIEXPORT void JNICALL
Java_com_mediatek_camera_feature_mode_visualsearch_utils_NativeImageDetect_destroyModel(JNIEnv *env,
                                                                                        jclass thiz) {
    __android_log_print(ANDROID_LOG_DEBUG, LOG_TAG, "release imageNeurPilot");
    if (imageNeurPilot != nullptr) {
        delete imageNeurPilot;
        imageNeurPilot = nullptr;
    }

    if (mCipherUtils != nullptr) {
        delete mCipherUtils;
        mCipherUtils = nullptr;
    }
}

}
