#import "ReactNativeYandexmapkit3.h"
#import <YandexMapKit/YMKMapKitFactory.h>


@implementation RNYandexMapKit

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(setApiKey: (nonnull NSString *) apiKey) {
    [YMKMapKit setApiKey: apiKey];
}

@end
