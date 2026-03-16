//
//  G711ATsToMovConvertor.h
//  Wansview
//
//  Created by HX on 2022/9/25.
//  Copyright © 2022 AJCloud. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "FFmpegManager.h"
NS_ASSUME_NONNULL_BEGIN

@interface G711ATsToMovConvertor : NSObject
+ (G711ATsToMovConvertor *)sharedConvertor;

-(void)G711aVideoFilePath:(NSString *)videoPath completionBlock:(void (^)(NSError *_Nullable error))completionBlock;
-(void)stopRuning;
@end

NS_ASSUME_NONNULL_END
