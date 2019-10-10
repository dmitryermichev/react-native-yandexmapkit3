#import <YandexMapKit/YMKResourceUrlProvider.h>
#import <YandexRuntime/YRTPlatformBinding.h>

@interface YMKDefaultResourceUrlProvider : YRTPlatformBinding<YMKResourceUrlProvider>

- (NSString *)formatUrlWithResourceId:(NSString *)resId;

- (void)setUrlBase:(NSString *)urlBase;

@end
