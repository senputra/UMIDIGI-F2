var appMsgs = {
    "error" : "Error occurs",
    "not_found" : "Not found",
}

var firmwaresMsgs = {
  "get/:firmwareId": {
    "firmwareid_nan": "Firmware ID is not a number",
    "firmwareid_notfound": "Firmware ID not found",
    "firmwareid_filename_notfound": "Firmware ID/Filename combination not found"
  }
}

var calibrationsMsgs = {
    "delete/" : {
        "missing_profileId" : "Missing required parameter: profileId",
        "success": "Success",
    },
    "get/" : {
        "missing_profileId" : "Missing required parameter: profileId",
    },
    "post/" : {
        "missing_profileId" : "Missing required parameter: profileId",
        "missing_body" : "Missing request body",
        "incorrect_body" : "Body should be an array with length 10",
        "contain_NaN" : "Array contains NaN value",
        "success" : "Success",
    },
}

var calibrationsV2Msgs = {
    "delete/" : {
        "missing_profileId" : "Missing required parameter: profileId",
        "success": "Success",
    },
    "get/" : {
        "missing_profileId" : "Missing required parameter: profileId",
    },
    "post/" : {
        "missing_profileId" : "Missing required parameter: profileId",
        "missing_body" : "Missing request body",
        "incorrect_body" : "Body should be an array with length 18",
        "contain_NaN" : "Array contains NaN value",
        "success" : "Success",
    },
}
    
var measurementsMsgs = {
    "put/:measurementId/data" : {
        "invalid_mid" : "Invalid measurement ID",
        "not_found" : "Not found",
        "duplicated" : "Multiple measurement occurence",
    },
    "get/:measurementId/data" : {
        "invalid_mid" : "Invalid measurement ID",
        "not_found" : "Not found",
        "duplicated" : "Multiple measurement occurence",
    },
    "get/:measurementId" : {
        "invalid_mid" : "Invalid measurement ID",
        "not_found" : "Not found",
        "duplicated" : "Multiple measurement occurence",
    },
    "get/" : {
        "invalid_pid" : "Invalid profile ID",
        "invalid_time": "Invalid startTime / endTime"
    },
    "post/" : {
        "missing_parameter" : "Request body must contains systolic, diastolic, spo2, heartrate, fatigue, pressure & timestamp",
        "not_found" : "Not found",
    },
}

var profilesMsgs = {
    "post/" : {
        "missing_parameter" : "Body must contains name, gender, birthday, height, weight and personalStatus",
        "invalid_gender" : "Field gender accepts the following options: male, female",
        "invalid_drug" : "Field personalStatus accepts the following options: none, hypertension, hypotension",
        "invalid_drugtime" : "Field takeMedicineTime accepts interger between 0 and 23",
        "invalid_bday" : "Field birthday accepts format: YYYY/MM/DD",
        "invalid_weight_height" : "Field weight and height accepts only integer",
        "invalid_weight_unit" : "Weightunit must be kg/jin/lb",
        "profile_exists" : "Profile already exists",
        "create_error" : "Cannot create profile",
    },
    "get/:profileId" : {
        "unauthorized" : "Unauthorized",
        "not_found" : "Not found",
    },
    "delete/:profileId" : {
        "missing_pid" : "Please input profile ID",
    },
    "put/:profileId" : {
        "invalid_drug" : "Field personalStatus accepts the following options: none, hypertension, hypotension",
        "invalid_drugtime" : "Field takeMedicineTime accepts interger between 0 and 23",
        "missing_pid" : "Please input profile ID",
        "no_body" : "No body was provided",
        "invalid_gender" : "Gender invalid",
        "not_found" : "Not found",
    },
}

var screeningsMsgs = {
    "get/" : {
        "permission_deinied" : "Permission Denied",
        "invalid_pid" : "Invalid profile ID",
    },
}

module.exports = {
    appMsgs: appMsgs,
    calibrationsMsgs: calibrationsMsgs,
    calibrationsV2Msgs: calibrationsV2Msgs,
    measurementsMsgs: measurementsMsgs,
    profilesMsgs: profilesMsgs,
    screeningsMsgs: screeningsMsgs,
    firmwaresMsgs: firmwaresMsgs
}
