/*******************************************************************************
 * Software Name : RCS IMS Stack
 *
 * Copyright (C) 2010 France Telecom S.A.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

package com.orangelabs.rcs.core.content;

import java.io.File;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Vector;

import com.orangelabs.rcs.core.ims.network.sip.SipUtils;
import com.orangelabs.rcs.core.ims.protocol.sdp.MediaAttribute;
import com.orangelabs.rcs.core.ims.protocol.sdp.MediaDescription;
import com.orangelabs.rcs.core.ims.protocol.sdp.SdpParser;
import com.orangelabs.rcs.core.ims.protocol.sip.SipRequest;
import com.orangelabs.rcs.platform.file.FileFactory;
import com.orangelabs.rcs.provider.settings.RcsSettings;
import com.orangelabs.rcs.utils.MimeManager;
import com.orangelabs.rcs.core.ims.protocol.rtp.codec.video.h264.H264Config;

import android.net.Uri;

/**
 * Multimedia content manager
 * 
 * @author jexa7410
 */
public class ContentManager{
    /**
     * Generate an URL for the received content
     * 
     * @param filename Filename
     * @param mime MIME type
     * @return URL
     */
    public static String generateUrlForReceivedContent(String filename, String mime) {
        // Generate a file path
        String path;
        if (mime.startsWith("image")) {
            path = RcsSettings.getInstance().getPhotoRootDirectory();
        } else
        if (mime.startsWith("video")) {
            path = RcsSettings.getInstance().getVideoRootDirectory();
        } else {
            path = RcsSettings.getInstance().getFileRootDirectory();
        }

        // Check that the filename will not overwrite existing file
        // We modify it if a file of the same name exists, by appending _1 before the extension
        // For example if image.jpeg exists, next file will be image_1.jpeg, then image_2.jpeg etc
        String extension = "";
        if ((filename!=null) && (filename.indexOf('.')!=-1)){
            // if extension is present, split it
            extension = "." + filename.substring(filename.lastIndexOf('.')+1);
            filename = filename.substring(0, filename.lastIndexOf('.'));
        }
        String destination = filename;
        int i = 1;
        while(FileFactory.getFactory().fileExists(path + destination + extension)){
            destination = filename + '_' + i;
            i++;
        }

        // Return free destination url
        return path + destination + extension;
    }


    public static MmContent createMmContent(Uri uri, String mime, long size, String fileName) {
        if (mime != null) {
            if (MimeManager.isImageType(mime)) {
                return new PhotoContent(uri, mime, size, fileName);
            }
            if (MimeManager.isVideoType(mime)) {
                return new VideoContent(uri, mime, size, fileName);
            }
            if (MimeManager.isAudioType(mime)) {
                return new AudioContent(uri, mime, size, fileName);
            }
        }
        return new FileContent(uri, size, fileName);
    }
    

    /**
     * Save a content in the local directory of the device
     *
     * @param content Content to be saved
     * @throws IOException
     */
    public static void saveContent(MmContent content) throws IOException {
        // Write data
        OutputStream os = FileFactory.getFactory().openFileOutputStream(content.getUrl());
        os.write(content.getData());
        os.flush();
        os.close();

        // Update the media storage
        FileFactory.getFactory().updateMediaStorage(content.getUrl());
    }

    /**
     * Create a content object from URL description
     * 
     * @param url Content URL
     * @param size Content size
     * @return Content instance
     */
    public static MmContent createMmContentFromUrl(String url, long size) {
        String ext = MimeManager.getFileExtension(url);
        String mime = MimeManager.getInstance().getMimeType(ext);
        return createMmContentFromMime(url, mime, size);
    }
    

    /**
     * Create a content object from Filename
     * 
     * @param filename Name of the file
     * @param url Content URL
     * @param size Content size
     * @return Content instance
     */
    public static MmContent createMmContentFromFilename(String filename, String url, long size) {
        String ext = MimeManager.getFileExtension(filename);
        String mime = MimeManager.getInstance().getMimeType(ext);
        MmContent content = createMmContentFromMime(url, mime, size);
        content.setName(filename);
        
        return content;
    }

    /**
     * Create a content object from MIME type
     * 
     * @param url Content URL
     * @param mime MIME type
     * @param size Content size
     * @return Content instance
     */
    public static MmContent createMmContentFromMime(String url, String mime, long size) {
        if (mime != null) {
            if (mime.startsWith("image/")) {
                // Photo content
                return new PhotoContent(url, mime, size);
            }
            if (mime.startsWith("audio/")) {
                // Audio content
                return new AudioContent(url, mime, size);
            }
            if (mime.startsWith("video/")) {
                // Video content
                return new VideoContent(url, mime, size);
            }
            if (RcsSettings.getInstance().supportOP01()) {
                if (mime.equals(XVisitCardContent.ENCODING)) {
                    // Visit Card content
                    return new XVisitCardContent(url, size);
                }
            } else {
                if (mime.equals(VisitCardContent.ENCODING)) {
                    // Visit Card content
                    return new VisitCardContent(url, size);
                }
            }
            if (mime.equals(VCalendarContent.ENCODING)) {
                // Visit Card content
                return new VCalendarContent(url, size);
            }
            if (mime.equals(GeolocContent.ENCODING)) {
                // Geoloc content
                return new GeolocContent(url, size, null);
            }
        }
        
        // File content
        return new FileContent(url, size);
    }

    /**
     * Create a live video content object
     * 
     * @param codec Codec
     * @return Content instance
     */
    public static LiveVideoContent createLiveVideoContent(String codec, int width, int height) {
    	 LiveVideoContent videoContent =new LiveVideoContent("video/"+codec);
         videoContent.setWidth(width);
         videoContent.setHeight(height);
         return videoContent;
    }
    
    /**
     * Create a live audio content object
     * 
     * @param codec Codec
     * @return Content instance
     */
    public static LiveAudioContent createLiveAudioContent(String codec) {
        return new LiveAudioContent("audio/"+codec);
    }

    /**
     * Create a generic live video content object
     * 
     * @return Content instance
     */
    public static LiveVideoContent createGenericLiveVideoContent() {
        return new LiveVideoContent("video/*");
    }
    
    /**
     * Create a generic live audio content object
     * 
     * @return Content instance
     */
    public static LiveAudioContent createGenericLiveAudioContent() {
        return new LiveAudioContent("audio/*");
    }

    /**
     * Create a live video content object
     * 
     * @param sdp SDP part
     * @return Content instance
     */
    public static LiveVideoContent createLiveVideoContentFromSdp(byte[] sdp) {
         // Parse the remote SDP part
        SdpParser parser = new SdpParser(sdp);
        Vector<MediaDescription> media = parser.getMediaDescriptions();
        if (media.size()==0) { // there is no media in SDP
            return null;
        }
        MediaDescription desc = media.elementAt(0);
        if (media.size()==1) { // if only one media in SDP, test if 'video', if not then return null         
            if (!desc.name.equals("video")) {
                return null;
            }    
        }    
        if (media.size()==2) { // if two media in SDP, test if first 'video', if not then choose second and test if video, if not return null
            if (!desc.name.equals("video")) {
                desc = media.elementAt(1);
                if (!desc.name.equals("video")) {
                    return null;
                }
            }    
        }        
    
        String rtpmap = desc.getMediaAttribute("rtpmap").getValue();

        // Extract the video encoding
        String encoding = rtpmap.substring(rtpmap.indexOf(desc.payload)+desc.payload.length()+1);
        String codec = encoding.toLowerCase().trim();
        int index = encoding.indexOf("/");
        if (index != -1) {
            codec = encoding.substring(0, index);
        }
        
        /* Extract video size */
        MediaAttribute frameSize = desc.getMediaAttribute("framesize");
        int width = 0;
        int height = 0;
        if (frameSize != null) {
            try {
                String value = frameSize.getValue();
                index = value.indexOf(desc.payload);
                int separator = value.indexOf('-');
                if (index != -1 && separator != -1) {
                    width = Integer.parseInt(value.substring(index + desc.payload.length() + 1,
                            separator));
                    height = Integer.parseInt(value.substring(separator + 1));
                }
            } catch (NumberFormatException e) {
                /* Use default value */
                width = H264Config.QCIF_WIDTH;
                height = H264Config.QCIF_HEIGHT;
            }
        }
        
        return createLiveVideoContent(codec,width,height);
    }
    
    /**
     * Create a live audio content object
     * 
     * @param sdp SDP part
     * @return Content instance
     */
    public static LiveAudioContent createLiveAudioContentFromSdp(byte[] sdp) {
         // Parse the remote SDP part
        SdpParser parser = new SdpParser(sdp);
        Vector<MediaDescription> media = parser.getMediaDescriptions(); // TODO replace with getMediaDescriptions(audio)
        if (media.size()==0) {
            return null;
        }
        MediaDescription desc = media.elementAt(0);
        if (media.size()==1) { // if only one media in SDP, test if 'audio', if not then return null         
            if (!desc.name.equals("audio")) {
                return null;
            }    
        }    
        if (media.size()==2) { // if two media in SDP, test if first 'audio', if not then choose second and test if 'audio', if not return null
            if (!desc.name.equals("audio")) {
                desc = media.elementAt(1);
                if (!desc.name.equals("audio")) {
                    return null;
                }
            }    
        }    
        if (!desc.name.equals("audio")) {
            return null;
        }    
        String rtpmap = desc.getMediaAttribute("rtpmap").getValue();

        // Extract the audio encoding
        String encoding = rtpmap.substring(rtpmap.indexOf(desc.payload)+desc.payload.length()+1);
        String codec = encoding.toLowerCase().trim();        
        int index = encoding.indexOf("/");
        if (index != -1) {
            codec = encoding.substring(0, index);
        }
        return createLiveAudioContent(codec);
    }

    /**
     * Create a content object from SDP description of a SIP invite request
     * 
     * @param invite SIP invite request
     * @return Content instance
     */
    public static MmContent createMmContentFromSdp(SipRequest invite) {
        try {
            String remoteSdp = invite.getSdpContent();
            SdpParser parser = new SdpParser(remoteSdp.getBytes());
            Vector<MediaDescription> media = parser.getMediaDescriptions();
            MediaDescription desc = media.elementAt(0);
            MediaAttribute attr1 = desc.getMediaAttribute("file-selector");
            String fileSelectorValue = attr1.getValue();
            String mime = SipUtils.extractParameter(fileSelectorValue, "type:", "application/octet-stream");
            long size = Long.parseLong(SipUtils.extractParameter(fileSelectorValue, "size:", "-1"));
            String filename = SipUtils.extractParameter(fileSelectorValue, "name:", "");
            String url = ContentManager.generateUrlForReceivedContent(filename, mime);                
            MmContent mContent = ContentManager.createMmContentFromMime(url, mime, size);
            return mContent;
        } catch(Exception e) {
            return null;
        }
    }
    
    /**
     * Create a content object from SDP description of a SIP invite request
     * 
     * @param invite SIP invite request
     * @return Content instance
     */
    public static MmContent createLargeMmContentFromSdp(SipRequest invite) {
        try {
            String remoteSdp = invite.getSdpContent();
            SdpParser parser = new SdpParser(remoteSdp.getBytes());
            Vector<MediaDescription> media = parser.getMediaDescriptions();
            MediaDescription desc = media.elementAt(0);
            MediaAttribute attr1 = desc.getMediaAttribute("file-selector");
            String fileSelectorValue = attr1.getValue();
            String mime = SipUtils.extractParameter(fileSelectorValue, "type:", "message/cpim");
            long size = Long.parseLong(SipUtils.extractParameter(fileSelectorValue, "size:", "-1"));
            String filename = SipUtils.extractParameter(fileSelectorValue, "name:", "largeMessage.txt");
            String url = ContentManager.generateUrlForReceivedContent(filename, mime);                
            MmContent mContent = ContentManager.createMmContentFromMime(url, mime, size);
            return mContent;
        } catch(Exception e) {
            return null;
        }
    }

    /**
     * Generate Uri for saving the content that has to be transferred
     *
     * @param fileName the file name
     * @param mime the MIME type
     * @param rcsSettings the RCS settings accessor
     * @return Uri
     */
    public static Uri generateUriForSentContent(String fileName, String mime
            ) {
        String path;
        if (mime.startsWith("image")) {
            path = RcsSettings.getInstance().getPhotoRootDirectory();
        } else
        if (mime.startsWith("video")) {
            path = RcsSettings.getInstance().getVideoRootDirectory();
        } else {
            path = RcsSettings.getInstance().getFileRootDirectory();
    }
        /*
         * Check that the fileName will not overwrite existing file We modify it if a file of the
         * same name exists, by appending _1 before the extension For example if image.jpeg exists,
         * next file will be image_1.jpeg, then image_2.jpeg etc.
         */

        if (fileName.indexOf('.') == -1) {
            throw new RuntimeException("Filename without extension: fileName='" + fileName + "'!");
        }
        /* if extension is present, split it */
        int extPosition = fileName.lastIndexOf('.');
        String extension = "." + fileName.substring(extPosition + 1);
        fileName = fileName.substring(0, extPosition);
        String destination = fileName;
        int incrementIndex = 1;
        File generatedFile = new File(path + destination + extension);
        while (generatedFile.exists()) {
            destination = fileName + '_' + incrementIndex;
            generatedFile = new File(path + destination + extension);
            incrementIndex++;
        }
        return Uri.fromFile(generatedFile);
    }

}
