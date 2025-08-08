//
//  ALFError.h
//
//
//  Created by Tianbao Wang on 2020/11/14.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ALFError : NSObject

@property (nonatomic, strong) NSString *message;
@property (nonatomic, assign) NSInteger code;

+ (ALFError *)errorWithMessage:(NSString *)message code:(NSInteger)code;
@end

NS_ASSUME_NONNULL_END
