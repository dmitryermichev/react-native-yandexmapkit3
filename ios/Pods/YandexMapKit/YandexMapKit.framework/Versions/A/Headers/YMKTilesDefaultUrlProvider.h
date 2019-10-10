#import <YandexMapKit/YMKTilesUrlProvider.h>
#import <YandexMapKit/YMKZoomRange.h>
#import <YandexRuntime/YRTPlatformBinding.h>

@interface YMKTilesDefaultUrlProvider : YRTPlatformBinding<YMKTilesUrlProvider>

- (NSString *)formatUrlWithTileId:(YMKTileId *)tileId
                          version:(YMKVersion *)version;

- (void)setUrlPattern:(NSString *)urlPattern;

- (void)setZoomRanges:(NSArray *)zoomRanges;

@end
