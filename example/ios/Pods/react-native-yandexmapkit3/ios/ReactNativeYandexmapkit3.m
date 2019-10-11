#import "ReactNativeYandexmapkit3.h"
#import <YandexMapKit/YMKMapKitFactory.h>


@implementation RNYandexMapKit

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(setApiKey: (nonnull NSString *) apiKey) {
    NSLog(@"set api key called");
    [YMKMapKit setApiKey: apiKey];
}

//RCT_EXPORT_METHOD(sampleMethod:(NSString *)stringArgument numberParameter:(nonnull NSNumber *)numberArgument callback:(RCTResponseSenderBlock)callback)
//{
//    // TODO: Implement some actually useful functionality
//    callback(@[[NSString stringWithFormat: @"numberArgument: %@ stringArgument: %@", numberArgument, stringArgument]]);
//}

@end
