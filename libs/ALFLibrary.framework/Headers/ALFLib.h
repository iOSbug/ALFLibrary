//
//  ALFLib.h
//  ALFLibrary
//
//  Created by Tianbao Wang on 2022/9/13.
//

#import <Foundation/Foundation.h>
#import <ALFLibrary/DiagnoseTCPManager.h>
#import <ALFLibrary/ObjcUtils.h>
#import <ALFLibrary/PlayViewController.h>
#import <ALFLibrary/HXCacheFileViewController.h>
#import <ALFLibrary/HXCacheFileManager.h>
#import <ALFLibrary/WVAlertDetailViewController.h>
#import <ALFLibrary/MWPhotoBrowser.h>
#import <ALFLibrary/MWPhoto.h>
#import <ALFLibrary/quadScreentVC.h>
#import <ALFLibrary/CameraStatusManager.h>
#import <ALFLibrary/TCPManager.h>
#import <ALFLibrary/NetworkUtility.h>

#import <ALFLibrary/WVNoDataHelpView.h>
#import <ALFLibrary/ChatViewController.h>
#import <ALFLibrary/WVConnectionManager.h>
#import <ALFLibrary/hardWareType.h>
#import <ALFLibrary/TelnetClient.h>
#import <ALFLibrary/HostEntry.h>
#import <ALFLibrary/StepSlider.h>
#import <ALFLibrary/CalenderUtil.h>
#import <ALFLibrary/LMJVerticalScrollText.h>
#import <ALFLibrary/CustomAVPlayerViewController.h>
#import <ALFLibrary/WKWebViewJavascriptBridge.h>
#import <ALFLibrary/SimplePingHelper.h>
#import <ALFLibrary/AlbumManager.h>
#import <ALFLibrary/DACircularProgressView.h>
#import <ALFLibrary/FeedRecordVC.h>
#import <ALFLibrary/FFmpegManager.h>
#import <ALFLibrary/ALFError.h>
#import <ALFLibrary/ALFBinder.h>
#import <ALFLibrary/ALFDevice.h>
#import <ALFLibrary/ALFMessage.h>
#import <ALFLibrary/ALFDownload.h>
#import <ALFLibrary/ALFSettings.h>
#import <ALFLibrary/ALFMediaPlayer.h>
#import <ALFLibrary/ALFWifiListModel.h>
#import <ALFLibrary/ALFDiscoverDeviceModel.h>
#import <ALFLibrary/ALFAlertsCalendarModel.h>
#import <ALFLibrary/ALFAlertsListModel.h>
#import <ALFLibrary/ALFCloudStorageModel.h>
#import <ALFLibrary/ALFAlarmListModel.h>
#import <ALFLibrary/ALFCloudStorageDeleteModel.h>
#import <ALFLibrary/ALFShare.h>
#import <ALFLibrary/ALFShareSendReceiverModel.h>
#import <ALFLibrary/ALFCocoaSecurity.h>
#import <ALFLibrary/ALFCloud.h>
#import <ALFLibrary/ALFCloudStorageModel.h>
#import <ALFLibrary/ALFTimezoneModel.h>
#import <ALFLibrary/ALFAccount.h>
#import <ALFLibrary/ALFGroup.h>
#import <ALFLibrary/ALFBanner.h>
#import <ALFLibrary/ALFGroupsModel.h>
#import <ALFLibrary/ALFBannerModel.h>
#import <ALFLibrary/ALFBindDeviceModel.h>
#import <ALFLibrary/ALFDefine.h>
#import <ALFLibrary/ALFViewAngleModel.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, ALFLoginStatus) {
    AJLoginExpire          = 1008,    ///Login expired (requires the app to redirect to the login page)
    AJLoginKickout         = 1011,    ///Single sign-on (kicked out)
};

@interface ALFLib : NSObject

/**
*    Singleton
*/
+ (instancetype)shared;

///Is the user logged in
@property(nonatomic,readonly) BOOL isLogin;

///Current user's account information, the account used during login
@property(nonatomic,strong,readonly)NSString *userAccount;

/**
 *   set as a test environment
 */
+ (void)setTestbed:(BOOL)testEnvirment;

/**
 *    The methods that the core library must call successfully complete initialization using the authentication data provided by the SDK publisher.
 *
 *    @param     securityID          SDK Library Authentication ID
 *    @param     securityKey       SDK library authentication code
 *    @param     allyName              Access vendors
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
+ (void)asyncInit:(NSString *)securityID
      securityKey:(NSString *)securityKey
         allyName:(NSString *)allyName
          success:(nullable void (^)(void))success
          failure:(nullable void (^)(ALFError *))failure;


@end

NS_ASSUME_NONNULL_END
