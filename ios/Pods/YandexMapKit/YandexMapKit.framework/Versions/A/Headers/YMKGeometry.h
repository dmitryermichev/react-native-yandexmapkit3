#import <YandexMapKit/YMKBoundingBox.h>
#import <YandexMapKit/YMKCircle.h>
#import <YandexMapKit/YMKPoint.h>
#import <YandexMapKit/YMKPolygon.h>
#import <YandexMapKit/YMKPolyline.h>

@interface YMKGeometry : NSObject

@property (nonatomic, readonly) YMKPoint *point;

@property (nonatomic, readonly) YMKPolyline *polyline;

@property (nonatomic, readonly) YMKPolygon *polygon;

@property (nonatomic, readonly) YMKBoundingBox *boundingBox;

@property (nonatomic, readonly) YMKCircle *circle;

+ (YMKGeometry *)geometryWithPoint:(YMKPoint *)point;

+ (YMKGeometry *)geometryWithPolyline:(YMKPolyline *)polyline;

+ (YMKGeometry *)geometryWithPolygon:(YMKPolygon *)polygon;

+ (YMKGeometry *)geometryWithBoundingBox:(YMKBoundingBox *)boundingBox;

+ (YMKGeometry *)geometryWithCircle:(YMKCircle *)circle;

@end

