// This source code is generated by UdpGeneratorTool, not recommend to modify it directly
package com.mediatek.location.lppe.bluetooth;

import com.mediatek.socket.base.SocketUtils.BaseBuffer;
import com.mediatek.socket.base.SocketUtils.Codable;

public enum BluetoothMultipleMeasurement implements Codable {
    forbidden,
    allowed,
    requested,
    end,
;

    public final static BluetoothMultipleMeasurement _instance = BluetoothMultipleMeasurement.forbidden;

    @Override
    public void encode(BaseBuffer buff) {
        switch (this) {
        case forbidden:
            buff.putInt(0);
            break;
        case allowed:
            buff.putInt(1);
            break;
        case requested:
            buff.putInt(2);
            break;
        case end:
            buff.putInt(2147483647);
            break;
        default:
            break;
        }
    }

    @Override
    public BluetoothMultipleMeasurement decode(BaseBuffer buff) {
        int _type = buff.getInt();
        switch (_type) {
        case 0:
            return forbidden;
        case 1:
            return allowed;
        case 2:
            return requested;
        case 2147483647:
            return end;
        }
        return null;
    }

    @Override
    public BluetoothMultipleMeasurement[] getArray(Codable[] data) {
        BluetoothMultipleMeasurement[] _out = new BluetoothMultipleMeasurement[data.length];
        for (int _i = 0; _i < data.length; _i++) {
            _out[_i] = (BluetoothMultipleMeasurement) data[_i];
        }
        return _out;
    }

}
