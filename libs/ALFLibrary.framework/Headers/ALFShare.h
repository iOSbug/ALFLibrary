//
//  ALFShare.h
//  ALFLibrary
//
//  Created by tmz on 2023/4/28.
//

#import <Foundation/Foundation.h>
#import "ALFShareSendReceiverModel.h"
#import "ALFError.h"

NS_ASSUME_NONNULL_BEGIN

@interface ALFShare : NSObject

/**
*    单例
*/
+ (instancetype)shared;

// MARK: API for Sender


/// Sender创建一个分享实例
/// @param deviceId 设备ID
/// @param receiverName 接受分享者的账号(trueID登录返回的sub)
/// @param receiverType 接收者账号类型 ("email", "phone", "ally"(三方快捷登录), "allyCode"(SDK))
/// @param prodName 设备prodName（cameraInfo.base.prodName）
/// @param success success
/// @param failure failure
- (void)createNewShare:(NSString *)deviceId
          receiverName:(NSString *)receiverName
          receiverType:(NSString *)receiverType
              prodName:(NSString *)prodName
               success:(nullable void (^)(ALFShareSendReceiverModel *))success
               failure:(nullable void (^)(ALFError *))failure;


/// 获取发起的设备分享信息
/// @param deviceId 设备ID
/// @param success success
/// @param failure failure
- (void)getShareSendInfo:(NSString *)deviceId
                 success:(nullable void (^)(NSArray<ALFShareSendReceiverModel *> *))success
                 failure:(nullable void (^)(ALFError *))failure;


/// 删除分享实例
/// @param deviceId 设备ID
/// @param receiverUid 接收者UID
/// @param success success
/// @param failure failure
- (void)deleteshared:(NSString *)deviceId
         receiverUid:(NSString *)receiverUid
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// 停用某分享
/// @param deviceId 设备ID
/// @param receiverUid 接收者UID
/// @param success success
/// @param failure failure
- (void)disableShareEntry:(NSString *)deviceId
              receiverUid:(NSString *)receiverUid
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// 开启某分享
/// @param deviceId 设备ID
/// @param receiverUid 接收者UID （ ShareSendReceiverModel.receiverUid ）
/// @param success success
/// @param failure failure
- (void)enableShareEntry:(NSString *)deviceId
             receiverUid:(NSString *)receiverUid
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(ALFError *))failure;



// MARK: API for Receiver

/// 接收者查询来自分享者的分享信息
/// @param success success
/// @param failure failure
- (void)getShareReceiveInfo:(nullable void (^)(NSArray<ALFShareSendReceiverModel *> *))success
                    failure:(nullable void (^)(ALFError *))failure;


/// 被分享者接受摄像头分享
///  @param deviceId 设备ID
/// @param senderUid  设备分享发起者的uid
/// @param success success
/// @param failure failure
- (void)receiveShare:(NSString *)deviceId
           senderUid:(NSString *)senderUid
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;

/// Receiver拒收分享
/// @param deviceId 设备ID
/// @param success success
/// @param failure failure
- (void)rejectShare:(NSString *)deviceId
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


/// Receiver删除分享摄像头
/// @param deviceId 设备ID
/// @param success success
/// @param failure failure
- (void)deteleSharedCamera:(NSString *)deviceId
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(ALFError *))failure;

@end

NS_ASSUME_NONNULL_END
