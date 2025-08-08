//
//  ALFDefine.h
//  ALFLibrary
//
//  Created by wtb on 2025/7/15.
//

#ifndef ALFDefine_h
#define ALFDefine_h

//账号属性
typedef NS_ENUM(NSInteger, ALFAccountGroup) {
    AccountGroupUnknown = 0,
    AccountGroupFBB,
    AccountGroupEnterprise
};

//设备属性
typedef NS_ENUM(NSInteger, ALFDeviceGroup) {
    DeviceGroupEnterprise = 0,
    DeviceGroupAIS,
    DeviceGroupCustomer,
    DeviceGroupBlacklisted
};


static NSString *UUIDActivationUrl = @"https://newfibre.ais.co.th/IPCamera/CustomerVerification";
static NSString *UUIDRegisterUrl = @"https://newfibre.ais.co.th/process/existingfibre";
static NSString *TBBCustomerUUIDActivationEnUrl = @"https://www.ais.th/en/consumers/fibre/services/cloud-ip-camera";
static NSString *TBBCustomerUUIDActivationThaiUrl = @"https://www.ais.th/consumers/fibre/services/cloud-ip-camera";
static NSString *AISTBBActivateCloudPackageLinkUrl = @"https://gate01-api.3bb.co.th/cloud_api/Check_miracle/checkAgent/eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJ0eXBlIjoibWFpbl9hcHAiLCJjb250ZW50X2lkIjoiIn0.lDF5RuddOJmOaClUbjL7mBpEcuy3AkWrJ_0BDdEG1uw/0/0";

#endif /* ALFDefine_h */
