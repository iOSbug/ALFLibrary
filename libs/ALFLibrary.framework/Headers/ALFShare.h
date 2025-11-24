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
*    Singleton
*/
+ (instancetype)shared;

// MARK: API for Sender


/// Create a sharing
/// @param deviceId  deviceId
/// @param receiverName  Accepting the sharer's account
/// @param receiverType Recipient account type ("email",  "allyCode" (SDK))
/// @param prodName device's prodName（cameraInfo.base.prodName）
/// @param success success
/// @param failure failure
- (void)createNewShare:(NSString *)deviceId
          receiverName:(NSString *)receiverName
          receiverType:(NSString *)receiverType
              prodName:(NSString *)prodName
               success:(nullable void (^)(ALFShareSendReceiverModel *))success
               failure:(nullable void (^)(ALFError *))failure;


/// Get the device shared information
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)getShareSendInfo:(NSString *)deviceId
                 success:(nullable void (^)(NSArray<ALFShareSendReceiverModel *> *))success
                 failure:(nullable void (^)(ALFError *))failure;


/// Delete share
/// @param deviceId deviceId
/// @param receiverUid receive UID
/// @param success success
/// @param failure failure
- (void)deleteshared:(NSString *)deviceId
         receiverUid:(NSString *)receiverUid
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;



/// Disable share
/// @param deviceId deviceId
/// @param receiverUid receive UID
/// @param success success
/// @param failure failure
- (void)disableShareEntry:(NSString *)deviceId
              receiverUid:(NSString *)receiverUid
                  success:(nullable void (^)(void))success
                  failure:(nullable void (^)(ALFError *))failure;


/// Enable share
/// @param deviceId deviceId
/// @param receiverUid eceive UID（ ShareSendReceiverModel.receiverUid ）
/// @param success success
/// @param failure failure
- (void)enableShareEntry:(NSString *)deviceId
             receiverUid:(NSString *)receiverUid
                 success:(nullable void (^)(void))success
                 failure:(nullable void (^)(ALFError *))failure;



// MARK: API for Receiver

/// The recipient queries the shared information from the sharer.
/// @param success success
/// @param failure failure
- (void)getShareReceiveInfo:(nullable void (^)(NSArray<ALFShareSendReceiverModel *> *))success
                    failure:(nullable void (^)(ALFError *))failure;


/// The recipient accepts camera sharing
///  @param deviceId deviceId
/// @param senderUid  UID of the device sharing initiator
/// @param success success
/// @param failure failure
- (void)receiveShare:(NSString *)deviceId
           senderUid:(NSString *)senderUid
             success:(nullable void (^)(void))success
             failure:(nullable void (^)(ALFError *))failure;

/// Receiver rejects sharing
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)rejectShare:(NSString *)deviceId
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


/// Receiver deletes shared camera
/// @param deviceId deviceId
/// @param success success
/// @param failure failure
- (void)deteleSharedCamera:(NSString *)deviceId
                   success:(nullable void (^)(void))success
                   failure:(nullable void (^)(ALFError *))failure;

@end

NS_ASSUME_NONNULL_END
