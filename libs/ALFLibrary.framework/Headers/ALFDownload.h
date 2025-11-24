//
//  ALFDownload.h
//  ALFLibrary
//
//  Created by tmz on 2023/2/21.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ALFDownload : NSObject

/**
*    Singleton
*/
+ (instancetype)shared;

/// Download cloud storage or alarm video
/// - Parameters:
///   - deviceId: deviceId
///   - mediasUrls: An array of video URLs can be passed; multiple URLs can be sent and will be merged into a single video in the end.
///   - downloadPath: Download path: If left blank, the download will default to the system photo album.
///   - progressHandler: Download progress
///   - successHandler: Download successful
///   - failureHandler: Download failed
- (void)downloadWithDeviceId:(NSString *)deviceId
                  mediasUrls:(NSArray *)mediasUrls
                downloadPath:(NSString *)downloadPath
             progressHandler:(nullable void (^)(float))progressHandler
              successHandler:(nullable void (^)(void))successHandler
              failureHandler:(nullable void (^)(NSError *))failureHandler;

@end

NS_ASSUME_NONNULL_END
