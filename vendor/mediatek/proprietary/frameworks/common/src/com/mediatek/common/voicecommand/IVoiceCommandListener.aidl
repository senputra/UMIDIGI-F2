package com.mediatek.common.voicecommand;

import android.os.Bundle;

@ProductApi
interface IVoiceCommandListener{
    void onVoiceCommandNotified(int mainAction , int subAction ,in Bundle extraData);
}
