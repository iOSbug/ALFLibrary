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
    AJLoginExpire          = 1008,    ///登录超期（需要app退到登录页面）
    AJLoginKickout         = 1011,    ///单点登录（被踢）
};

@interface ALFLib : NSObject

/**
*    单例
*/
+ (instancetype)shared;

///用户是否已登录
@property(nonatomic,readonly) BOOL isLogin;

///当前用户的账号信息，登录时的account
@property(nonatomic,strong,readonly)NSString *userAccount;


/**
 *    核心库必须调用的方法，通过SDK发布方提供的鉴权数据正常完成初始化
 *
 *    @param     securityID          SDK库鉴权ID
 *    @param     securityKey       SDK库鉴权码
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
+ (void)asyncInit:(NSString *)securityID
      securityKey:(NSString *)securityKey
          success:(nullable void (^)(void))success
          failure:(nullable void (^)(ALFError *))failure;


@end

NS_ASSUME_NONNULL_END
