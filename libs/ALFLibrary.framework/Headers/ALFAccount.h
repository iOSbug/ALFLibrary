//
//  ALFAccount.h
//  ALFLibrary
//
//  Created by wtb on 2025/7/14.
//

#import <Foundation/Foundation.h>
#import "ALFError.h"
#import "ALFDefine.h"

NS_ASSUME_NONNULL_BEGIN



@interface ALFAccount : NSObject
/**
*    单例
*/
+ (instancetype)shared;


/**
 *    登录
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)signin:(NSString *)account
      password:(NSString *)password
       success:(nullable void (^)(void))success
       failure:(nullable void (^)(ALFError *))failure;



/**
 *    注册
 *    Step1: signupCheck; Step2: signup (send email verifyCode); Step3: accountActive (developer need to call this api themselves)
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */
- (void)signup:(NSString *)account
      password:(NSString *)password
       success:(nullable void (^)(void))success
       failure:(nullable void (^)(ALFError *))failure;


/**
 *    退出登录
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)signout:(nullable void (^)(void))success
        failure:(nullable void (^)(ALFError *))failure;



/**
 *    注销账号
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)deleteAccount:(NSString *)account
             password:(NSString *)password
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;

/**
 *    账号是否注册过
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)signupCheck:(NSString *)username
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


//邮箱校验验证码
- (void)accountActive:(NSString *)account
           verifyCode:(NSString *)verifyCode
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;


//忘记密码
- (void)resetPassword:(NSString *)account
             password:(NSString *)password
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;


//修改密码
- (void)changePassword:(NSString *)account
           oldPassword:(NSString *)oldPassword
           newPassword:(NSString *)newPassword
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;



//uuid激活
- (void)uuidActive:(NSString *)uuid
           success:(nullable void (^)(void))success
           failure:(nullable void (^)(ALFError *))failure;


/**
 *    请求验证码(AIS 修改email)
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)emailSetReq:(NSString *)email
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


/**
 *    修改email(AIS 修改email)
 *    @param     success                成功 回调
 *    @param     failure                失败回调
 */

- (void)emailSetVerify:(NSString *)email
            verifyCode:(NSString *)verifyCode
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;



/**
 *    登录账号的角色
 */
- (ALFAccountGroup)getAccountGroup;


/**
 *    登录账号的uuid
 */
- (NSString *)getAccountUUID;


- (NSString *)getCurrentAccount;

- (NSString *)getAccountBindEmail;

@end

NS_ASSUME_NONNULL_END
