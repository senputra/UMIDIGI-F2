set testMode=%1
set LOCAL_DIR=%~dp0
echo "Install certificate for WPA3 ..."

adb shell chmod 777 /data/misc/wifi/
adb push %LOCAL_DIR%\wifi.cfg data/misc/wifi/
adb push %LOCAL_DIR%\cas.pem data/misc/wifi/
adb push %LOCAL_DIR%\wifiuser.pem data/misc/wifi/
adb push %LOCAL_DIR%\wifiuser.key data/misc/wifi/
adb push %LOCAL_DIR%\rsa_ca1_w1_fi.pem data/misc/wifi/
adb push %LOCAL_DIR%\rsa_ca2_w1_fi.pem data/misc/wifi/
adb push %LOCAL_DIR%\rsa_server1_w1_fi.pem data/misc/wifi/
adb push %LOCAL_DIR%\rsa_server1_w1_fi.pem.sha256 data/misc/wifi/
adb push %LOCAL_DIR%\rsa_server1ALT_w1_fi.pem data/misc/wifi/
adb push %LOCAL_DIR%\rsa_server1ALT_w1_fi.pem.sha256 data/misc/wifi/
adb push %LOCAL_DIR%\rsa_server1ALT_w1_fi.pem.tod data/misc/wifi/
adb push %LOCAL_DIR%\rsa_server2_w1_fi.pem data/misc/wifi/
adb push %LOCAL_DIR%\rsa_server2_w1_fi.pem.sha256 data/misc/wifi/
adb push %LOCAL_DIR%\rsa_user1_w1_fi.pem data/misc/wifi/
adb push %LOCAL_DIR%\rsa-user1.p12 data/misc/wifi/