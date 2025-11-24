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
*    Singleton
*/
+ (instancetype)shared;


/**
 *    SDK Login
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)fastSignin:(NSString *)allyToken
           success:(nullable void (^)(void))success
           failure:(nullable void (^)(ALFError *))failure;


/**
 *    SDK Logout
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)fastSignout:(NSString *)allyToken
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


/**
 *    Login（email & password）
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)signin:(NSString *)account
      password:(NSString *)password
       success:(nullable void (^)(void))success
       failure:(nullable void (^)(ALFError *))failure;



/**
 *    Register（email & password）
 *    Step1: signupCheck; Step2: signup (send email verifyCode); Step3: accountActive (developer need to call this api themselves)
 *    @param     success                Successful callback
 *    @param     failure               Failure callback
 */
- (void)signup:(NSString *)account
      password:(NSString *)password
       success:(nullable void (^)(void))success
       failure:(nullable void (^)(ALFError *))failure;


/**
 *    Logout
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)signout:(nullable void (^)(void))success
        failure:(nullable void (^)(ALFError *))failure;



/**
 *    Delete account
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)deleteAccount:(NSString *)account
             password:(NSString *)password
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;

/**
 *    Has the account been registered
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */
- (void)signupCheck:(NSString *)username
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


///Email verification code
- (void)accountActive:(NSString *)account
           verifyCode:(NSString *)verifyCode
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;


///forget the password
- (void)resetPassword:(NSString *)account
             password:(NSString *)password
              success:(nullable void (^)(void))success
              failure:(nullable void (^)(ALFError *))failure;


///Change password
- (void)changePassword:(NSString *)account
           oldPassword:(NSString *)oldPassword
           newPassword:(NSString *)newPassword
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;



///UUID activation
- (void)uuidActive:(NSString *)uuid
           success:(nullable void (^)(void))success
           failure:(nullable void (^)(ALFError *))failure;


/**
 *    Request verification code (AIS email modification)
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)emailSetReq:(NSString *)email
            success:(nullable void (^)(void))success
            failure:(nullable void (^)(ALFError *))failure;


/**
 *    Edit email (AIS edit email)
 *    @param     success                Successful callback
 *    @param     failure                Failure callback
 */

- (void)emailSetVerify:(NSString *)email
            verifyCode:(NSString *)verifyCode
               success:(nullable void (^)(void))success
               failure:(nullable void (^)(ALFError *))failure;



/**
 *    Login account role
 */
- (ALFAccountGroup)getAccountGroup;


/**
 *    UUID of the login account
 */
- (NSString *)getAccountUUID;


- (NSString *)getCurrentAccount;

- (NSString *)getAccountBindEmail;

@end

NS_ASSUME_NONNULL_END
