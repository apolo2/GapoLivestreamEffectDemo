// Copyright (C) 2019 Beijing Bytedance Network Technology Co., Ltd.
#ifndef EFFECT_SDK_BEF_EFFECT_AI_PUBLIC_DEFINE_H
#define EFFECT_SDK_BEF_EFFECT_AI_PUBLIC_DEFINE_H


#define BEF_INTENSITY_TYPE_NONE                 0
#define BEF_INTENSITY_TYPE_BEAUTY_WHITEN        1   //  {zh} 美白  {en} Whitening
#define BEF_INTENSITY_TYPE_BEAUTY_SMOOTH        2   //  {zh} 磨平  {en} Smooth
#define BEF_INTENSITY_TYPE_FACE_SHAPE           3   //  {zh} 大眼/瘦脸  {en} Big eyes/thin face
#define BEF_INTENSITY_TYPE_BEAUTY_SHARP         9   //  {zh} 锐化  {en} Sharpening
#define BEF_INTENSITY_TYPE_GLOBAL_FILTER_V2     12  //  {zh} 滤镜  {en} Filter
#define BEF_INTENSITY_TYPE_BUILDIN_LIP          17  //  {zh} 唇色  {en} Lip color
#define BEF_INTENSITY_TYPE_BUILDIN_BLUSHER      18  //  {zh} 腮红  {en} Blush
#ifdef BEF_SDK_API
#undef BEF_SDK_API
#endif

//bef_framework_public_base_define
#    ifdef __cplusplus
#        ifdef _EFFECT_SDK_EXPORTS_
#            define BEF_SDK_API extern "C" __attribute__((visibility ("default")))
#        else
#            define BEF_SDK_API extern "C"
#        endif
#    else
#        ifdef _EFFECT_SDK_EXPORTS_
#            define BEF_SDK_API __attribute__((visibility ("default")))
#        else
#            define BEF_SDK_API
#        endif
#    endif


typedef    short           int16_t;
typedef    int             int32_t;

typedef unsigned long long UINT64;
// def byted effect handle
typedef void *bef_effect_handle_t;

// def byted effect result
typedef int bef_effect_result_t;

typedef int effect_result;

// define bef_intensity_type
typedef int bef_intensity_type;

// start error code
#define BEF_RESULT_SUC                       0  //  {zh} 成功返回  {en} Successful return
#define BEF_RESULT_FAIL                     -1  //  {zh} 内部错误，检查是否初始化，初始化是否成功  {en} Internal error, check whether initialization is successful
#define BEF_RESULT_FILE_NOT_FIND            -2  //  {zh} 文件没找到，检查代码中的文件路径与实际路径是否匹配  {en} File not found, check whether the file path in the code matches the actual path

#define BEF_RESULT_INVALID_INTERFACE        -3  //  {zh} 接口未实现，检查SDK是否具备该功能  {en} The interface is not implemented, check whether the SDK has this function
#define BEF_RESULT_FILE_OPEN_FAILED         -4  //  {zh} 文件打开失败，检查文件是否存在，检查对目标文件是否有读写权限  {en} File opening failed, check whether the file exists, check whether there are read and write permissions on the target file

#define BEF_RESULT_INVALID_EFFECT_HANDLE    -5  //  {zh} 无效的Effect句柄，检查是否初始化，初始化是否成功  {en} Invalid Effect handle to check whether initialization is successful
#define BEF_RESULT_INVALID_EFFECT_MANAGER   -6  //  {zh} 无效的EffectManager，检查是否初始化，初始化是否成功  {en} Invalid EffectManager, check whether initialization is successful
#define BEF_RESULT_INVALID_FEATURE_HANDLE   -7  //  {zh} 无效的Feature句柄，检查是否初始化，初始化是否成功  {en} Invalid Feature handle to check whether initialization is successful
#define BEF_RESULT_INVALID_FEATURE          -8  //  {zh} 无效的Feature，检查是否初始化，初始化是否成功  {en} Invalid Feature, check whether initialization is successful
#define BEF_RESULT_INVALID_RENDER_MANAGER   -9  //  {zh} 无效的RenderManager，检查是否初始化，初始化是否成功  {en} Invalid RenderManager, check whether initialization is successful
#define BEF_RESULT_INVALID_ALG_RES          -11 //  {zh} 无效的算法结果，没有设置美颜等特效可能会有这个报错，大部分情况下可忽略  {en} Invalid algorithm results, no special effects such as beauty setting may have this error, which can be ignored in most cases
#define BEF_RESULT_INVALID_ALG_FACE_RES     -12 //  {zh} 无效的人脸检测结果  {en} Invalid face detection results
#define BEF_RESULT_INVALID_ALG_CAT_FACE_RES -13 //  {zh} 无效的猫脸检测结果  {en} Invalid cat face test results
#define BEF_RESULT_INVALID_ALG_HAND_RES     -14 //  {zh} 无效的手势检测结果  {en} Invalid gesture detection result
#define BEF_RESULT_INVALID_ALG_BODY_RES     -15 //  {zh} 无效的人体检测结果  {en} Invalid human test results
#define BEF_RESULT_ALG_INIT_FAIL            -17 //  {zh} 算法初始化失败  {en} Algorithm initialization failed
#define BEF_RESULT_ALG_FACE_INIT_FAIL       -21 //  {zh} 人脸检测初始化失败  {en} Face detection initialization failed
#define BEF_RESULT_ALG_FACE_106_CREATE_FAIL -22 //  {zh} 人脸检测106算法创建失败，检查 license 是否有效，检查模型是否有效  {en} Face detection 106 algorithm creation failed, check whether the license is valid, check whether the model is valid
#define BEF_RESULT_ALG_FACE_280_CREATE_FAIL -23 //  {zh} 人脸检测280算法创建失败，检查 license 是否有效，检查模型是否有效  {en} Face detection 280 algorithm creation failed, check whether the license is valid, check whether the model is valid
#define BEF_RESULT_ALG_FACE_PREDICT_FAIL    -24 //  {zh} 人脸检测预测失败，检查传入图像是否正确  {en} Face detection prediction failed, check whether the incoming image is correct
#define BEF_RESULT_ALG_EXP_CREATE_FAIL      -25 //  {zh} 表情检测初始化失败，检查 license 是否有效，检查模型是否有效  {en} Expression detection initialization failed, check whether the license is valid, check whether the model is valid
#define BEF_RESULT_ALG_HAND_CREATE_FAIL     -26 //  {zh} 创建手势算法失败，检查 license 是否有效，检查模型是否有效  {en} Failed to create gesture algorithm, check whether the license is valid, check whether the model is valid
#define BEF_RESULT_ALG_HAND_PREDICT_FAIL    -27 //  {zh} 手势算法预测失败，检查传入图像是否正确  {en} Gesture algorithm failed to predict, check whether the incoming image is correct


#define BEF_RESULT_INVALID_TEXTURE          -36 //  {zh} 无效的texture，检查传入 texture 是否正确  {en} Invalid texture, check whether the incoming texture is correct
#define BEF_RESULT_INVALID_IMAGE_DATA       -37 //  {zh} 无效的图像数据，检查传入 buffer 是否正确  {en} Invalid image data, check whether the incoming buffer is correct
#define BEF_RESULT_INVALID_IMAGE_FORMAT     -38 //  {zh} 无效的图片格式，检查传入的图像格式是否符合要求  {en} Invalid image format, check whether the incoming image format meets the requirements
#define BEF_RESULT_INVALID_PARAM_TYPE       -39 //  {zh} 无效的参数类型，检查传入的参数是否符合要求  {en} Invalid parameter type, check whether the passed parameter meets the requirements
#define BEF_RESULT_INVALID_RESOURCE_VERSION -40 //  {zh} 资源文件指定sdk版本过高，检查资源文件是否正确  {en} The resource file specifies that the sdk version is too high, check whether the resource file is correct
#define BEF_RESULT_INVALID_PARAM_VALUE      -47 //  {zh} 无效的参数值，检查传入的参数是否符合要求  {en} Invalid parameter value, check whether the passed parameter meets the requirements

#define BEF_RESULT_SMASH_E_INTERNAL         -101 //  {zh} 未定义内部错误，请联系技术支持  {en} No internal error defined, please contact technical support
#define BEF_RESULT_SMASH_E_NOT_INITED       -102 //  {zh} 未初始化相关资源，请联系技术支持  {en} Not initializing related resources, please contact technical support
#define BEF_RESULT_SMASH_E_MALLOC           -103 //  {zh} 申请内存失败，请联系技术支持  {en} Failed to request memory, please contact technical support
#define BEF_RESULT_SMASH_E_INVALID_PARAM    -104 //  {zh} 无效的参数，检查传入的参数是否符合要求  {en} Invalid parameter, check whether the passed parameter meets the requirements
#define BEF_RESULT_SMASH_E_ESPRESSO         -105 //  {zh} ESPRESSO错误，请联系技术支持  {en} ESPRESSO error, please contact technical support
#define BEF_RESULT_SMASH_E_MOBILECV         -106 //  {zh} MOBILECV错误，请联系技术支持  {en} MOBILECV error, please contact technical support
#define BEF_RESULT_SMASH_E_INVALID_CONFIG   -107 //  {zh} 无效的配置，请检查传入授权文件路径是否正确，授权文件是否受损  {en} Invalid configuration, please check whether the path of the incoming authorization file is correct and whether the authorization file is damaged
#define BEF_RESULT_SMASH_E_INVALID_HANDLE   -108 //  {zh} 无效的句柄，请检查传入授权文件路径是否正确，授权文件是否受损  {en} Invalid handle, please check whether the path of the incoming authorization file is correct and whether the authorization file is damaged
#define BEF_RESULT_SMASH_E_INVALID_MODEL    -109 //  {zh} 无效的模型，请检查传入授权文件路径是否正确，授权文件是否受损  {en} Invalid model, please check whether the path of the incoming authorization file is correct and whether the authorization file is damaged
#define BEF_RESULT_SMASH_E_INVALID_PIXEL_FORMAT        -110 //  {zh} 无效的图像格式，请检查传入图像格式是否在SDK支持的范围内  {en} Invalid image format, please check whether the incoming image format is within the scope supported by the SDK
#define BEF_RESULT_SMASH_E_INVALID_POINT               -111 //  {zh} 无效的点，请检查传入接口的输入或输出变量是否为null  {en} Invalid point, please check whether the input or output variable of the incoming interface is null
#define BEF_RESULT_SMASH_E_REQUIRE_FEATURE_NOT_INIT    -112 //  {zh} 依赖模块没有初始化，请联系技术支持  {en} The dependency module is not initialized, please contact technical support
#define BEF_RESULT_SMASH_E_NOT_IMPL                    -113 //  {zh} 未实现的接口，请检查调用函数名和参数是否正确  {en} Unimplemented interface, please check whether the calling function name and parameters are correct

#define BEF_RESULT_INVALID_LICENSE                     -114 //  {zh} 无效的license，请检查授权文件路径是否正确，模型文件是否受损  {en} Invalid license, please check whether the authorization file path is correct and whether the model file is damaged
#define BEF_RESULT_NULL_BUNDLEID                       -115 //  {zh} Application/Bundle ID 为空，请检查传入bundle Id或ApplicationId是否为空  {en} Application/Bundle ID is empty, please check whether the incoming bundle Id or ApplicationId is empty
#define BEF_RESULT_LICENSE_STATUS_INVALID              -116 //  {zh} 非法授权文件，请检查授权文件是否正确  {en} Illegal authorization file, please check whether the authorization file is correct
#define BEF_RESULT_LICENSE_STATUS_EXPIRED              -117 //  {zh} 授权文件过期，请检查授权文件是否正确，是否需要更新  {en} The authorization file has expired, please check whether the authorization file is correct and whether it needs to be updated
#define BEF_RESULT_LICENSE_STATUS_NO_FUNC              -118 //  {zh} 请求功能不匹配，请检查是否购买对应功能  {en} The request function does not match, please check whether to purchase the corresponding function
#define BEF_RESULT_LICENSE_STATUS_ID_NOT_MATCH         -119 //  {zh} Application/Bundle ID 不匹配，请检查申请授权文件和应用的Application/BundleId是否一致  {en} Application/Bundle IDs do not match, please check whether the application authorization file is consistent with the application/BundleId of the application

#define BEF_RESULT_LICENSE_BAG_NULL_PATH               -120 //  {zh} 授权包路径为空，请检查授权文件路径是否正确  {en} The path of the authorization package is empty, please check whether the path of the authorization file is correct
#define BEF_RESULT_LICENSE_BAG_INVALID_PATH            -121 //  {zh} 错误的授权包路径，请检查传入sdk的路径是否正确  {en} Wrong authorization package path, please check whether the path passed into sdk is correct
#define BEF_RESULT_LICENSE_BAG_TYPE_NOT_MATCH          -122 //  {zh} 授权包类型不匹配，请检查授权文件是否正确，是否损坏  {en} Authorization package type does not match, please check whether the authorization file is correct and damaged
#define BEF_RESULT_LICENSE_BAG_INVALID_VERSION         -123 //  {zh} 无效的版本，请检查是否用了旧版本的授权文件  {en} Invalid version, please check whether the old version of the authorization file is used
#define BEF_RESULT_LICENSE_BAG_INVALID_BLOCK_COUNT     -124 //  {zh} 无效的数据块，请检查授权文件是否正确，是否损坏  {en} Invalid data block, please check whether the authorization file is correct and damaged
#define BEF_RESULT_LICENSE_BAG_INVALID_BLOCK_LEN       -125 //  {zh} 无效的数据块长度，请检查授权文件是否正确，是否损坏  {en} Invalid data block length, please check whether the authorization file is correct and damaged
#define BEF_RESULT_LICENSE_BAG_INCOMPLETE_BLOCK        -126 //  {zh} 数据块不完整，请检查授权文件是否正确，是否损坏  {en} The data block is incomplete, please check whether the authorization file is correct and damaged
#define BEF_RESULT_LICENSE_BAG_UNAUTHORIZED_FUNC       -127 //  {zh} license未授权的功能，请检查是否购买对应功能  {en} License unauthorized functions, please check whether to purchase corresponding functions

#define BEF_RESULT_SDK_FUNC_NOT_INCLUDE                -128 //  {zh} SDK 未包含功能  {en} SDK does not include features
#define BEF_RESULT_LICENSE_BAG_INVALID_SUB_FUNC        -129 //  {zh} 无效的subFunction，证书存在问题，请联系技术支持  {en} Invalid subFunction, there is a problem with the certificate, please contact technical support
#define BEF_RESULT_GL_ERROR_OCCUR                      -150 //  {zh} opengl发生错误，请检查是否在opengl线程调用接口  {en} An error occurred in opengl, please check whether the interface is called in the opengl thread
#define BEF_RESULT_GL_CONTECT                          -151 //  {zh} 无效的glcontext，请检查gl上下文是否正确  {en} Invalid glcontext, please check if the gl context is correct
#define BEF_RESULT_GL_TEXTURE                          -152 //  {zh} 无效的gltexture，请检查纹理号是否有效  {en} Invalid gltexture, please check whether the texture number is valid


/* {zh}
 ** 画质增强的错误码都放在这里
 */
/* {en}
 ** The enhanced image error codes are all here
 */
#define BEF_RESULT_IMAGE_QUALITY_CREATE_ENGINE_FAILED           -64     //  {zh} 画质增强引擎创建失败  {en} Image quality enhancement engine creation failed
#define BEF_RESULT_IMAGE_QUALITY_CREATE_VIDEO_SR_FAILED         -65     //  {zh} 视频超分算法创建失败  {en} Video super-segmentation algorithm creation failed
#define BEF_RESULT_IMAGE_QUALITY_CREATE_NIGHT_SCENE_FAILED      -66     //  {zh} 画质算法失败  {en} Image quality algorithm failed
#define BEF_RESULT_INVALID_HANDLE                               -67     //  {zh} 无效的画质算法handle  {en} Invalid image quality algorithm handling
#define BEF_RESULT_IMAGE_QUALITY_CREATE_ADAPTIVE_SHARPEN_FAILED      -68     //  {zh} 画质算法失败  {en} Image quality algorithm failed
#define BEF_RESULT_IMAGE_QUALITY_ASP_UNDER_INIT                 -69     //  {zh} 画质自适应锐化异步处理，设置完成会继续处理  {en} Image quality adaptive sharpening asynchronous processing, processing will continue after setting
/*
 ** END
 */
// end error code

#define BEF_EFFECT_FEATURE_LEN                          128 // {zh} feature name 默认长度 {en} Feature name default length

// bef_framework_public_geometry_define
// @brief image rotate type definition
typedef enum {
    BEF_AI_CLOCKWISE_ROTATE_0 = 0, //  {zh} 图像不需要旋转，图像中的人脸为正脸  {en} The image does not need to be rotated, and the faces in the image are positive faces
    BEF_AI_CLOCKWISE_ROTATE_90 = 1, //  {zh} 图像需要顺时针旋转90度，使图像中的人脸为正  {en} The image needs to be rotated 90 degrees clockwise to make the face in the image positive
    BEF_AI_CLOCKWISE_ROTATE_180 = 2, //  {zh} 图像需要顺时针旋转180度，使图像中的人脸为正  {en} The image needs to be rotated 180 degrees clockwise to make the face in the image positive
    BEF_AI_CLOCKWISE_ROTATE_270 = 3  //  {zh} 图像需要顺时针旋转270度，使图像中的人脸为正  {en} The image needs to be rotated 270 degrees clockwise to make the face in the image positive
} bef_ai_rotate_type;

// ORDER!!!
typedef enum {
    BEF_AI_PIX_FMT_RGBA8888, //  {zh} RGBA 8:8:8:8 32bpp ( 4通道32bit RGBA 像素 )  {en} RGBA 8:8:8:8 32bpp (4-channel 32bit RGBA pixels)
    BEF_AI_PIX_FMT_BGRA8888, //  {zh} BGRA 8:8:8:8 32bpp ( 4通道32bit RGBA 像素 )  {en} BGRA 8:8:8:8 32bpp (4-channel 32bit RGBA pixels)
    BEF_AI_PIX_FMT_BGR888,   //  {zh} BGR 8:8:8 24bpp ( 3通道32bit RGB 像素 )  {en} BGR 8:8:8 24bpp (3-channel 32bit RGB pixels)
    BEF_AI_PIX_FMT_RGB888,   //  {zh} RGB 8:8:8 24bpp ( 3通道32bit RGB 像素 )  {en} RGB 8:8:8 24bpp (3-channel 32bit RGB pixels)
    BEF_AI_PIX_FMT_GRAY8,    //  {zh} GRAY 8bpp ( 1通道8bit 灰度像素 ). 目前还不支持  {en} GRAY 8bpp (1 channel 8bit grayscale pixels). Currently not supported
    BEF_AI_PIX_FMT_YUV420P,  //  {zh} YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另两个为U分量和V分量通道, 所有通道都是连续的 ). 目前还不支持  {en} YUV 4:2:0 12bpp (3 channels, one brightness channel, the other two are U component and V component channels, all channels are continuous). Currently not supported
    BEF_AI_PIX_FMT_NV12,     //  {zh} YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另一道为UV分量交错 ). 目前还不支持  {en} YUV 4:2:0 12bpp (3 channels, one brightness channel, the other is UV component interleaving). Currently not supported
    BEF_AI_PIX_FMT_NV21      //  {zh} YUV  4:2:0   12bpp ( 3通道, 一个亮度通道, 另一道为VU分量交错 ). 目前还不支持  {en} YUV 4:2:0 12bpp (3 channels, one brightness channel, the other is interleaved with VU components). Currently not supported
} bef_ai_pixel_format;


typedef struct bef_ai_fpoint_t {
    float x;
    float y;
} bef_ai_fpoint;

typedef struct bef_ai_fpoint3d_t {
    float x;
    float y;
    float z;
} bef_ai_fpoint3d;

typedef struct bef_ai_rect_t {
    int left;   //  {zh} Left most coordinate in rectangle. 矩形最左边的坐标  {en} Left most coordinates in rectangle
    int top;    //  {zh} Top coordinate in rectangle.  矩形最上边的坐标  {en} Top coordinates in rectangle. The top coordinates of a rectangle
    int right;  //  {zh} Right most coordinate in rectangle.  矩形最右边的坐标  {en} Right most coordinates in rectangle. Right most coordinates in rectangle
    int bottom; //  {zh} Bottom coordinate in rectangle. 矩形最下边的坐标  {en} Bottom coordinates in rectangle. The coordinates of the bottom of the rectangle
} bef_ai_rect;

// Same definiation as bef_rect, but in float type
//  {zh} 和bef_rect一样的定义，类型为单精度浮点  {en} Same definition as bef_rect, type is single precision floating point
typedef struct bef_ai_rectf_t {
    float left;
    float top;
    float right;
    float bottom;
} bef_ai_rectf;


typedef enum bef_ai_camera_position_t {
    bef_ai_camera_position_front,
    bef_ai_camera_position_back
} bef_ai_camera_position;



typedef struct bef_ai_frect_st {
    float left;   // {zh} /< 矩形最左边的坐标 {en} /< The leftmost coordinate of the rectangle
    float top;    // {zh} /< 矩形最上边的坐标 {en} /< Coordinates of the top of the rectangle
    float right;  // {zh} /< 矩形最右边的坐标 {en} /< The rightmost coordinates of the rectangle
    float bottom; // {zh} /< 矩形最下边的坐标 {en} /< The coordinates of the bottom of the rectangle
} bef_ai_frect;


typedef struct bef_ai_image_t {
    const unsigned char *data;
    int width;
    int height;
    int stride;
    int format;
    bef_ai_rotate_type rotate;
} bef_ai_image;

typedef struct bef_ai_tt_key_point_st {
    float x; //  {zh} 对应 cols, 范围在 [0, width] 之间  {en} Correspondence col, range between [0, width]
    float y; //  {zh} 对应 rows, 范围在 [0, height] 之间  {en} Corresponding rows, range between [0, height]
    bool is_detect; //  {zh} 如果该值为 false, 则 x,y 无意义  {en} If the value is false, then x, y are meaningless
} bef_ai_tt_key_point;

typedef struct {
    const unsigned char* image;          // {zh} /< 图像帧数据地址 {en} /< Image frame data address
    bef_ai_pixel_format pixel_fmt;       // {zh} /< 图像格式 {en} /< Image format
    int image_width;                     // {zh} /< 图像的宽度 {en} /< Width of image
    int image_height;                    // {zh} /< 图像的高度 {en} /< Height of image
    int image_stride;                    // {zh} /< 图像的步长(每行的字节数，可能存在padding) {en} /< Step size of the image (number of bytes per line, padding may exist)
    bef_ai_rotate_type orient;           // {zh} /< 图像的方向 {en} /< Image orientation
} bef_ai_base_args;

typedef enum {
    bef_ai_render_api_gles20 = 0,
    bef_ai_render_api_gles30,
} bef_ai_render_api_type;

typedef enum {
    BEF_AI_TOUCH_EVENT_BEGAN,         // {zh} /< 触摸开始事件 {en} /< Touch start event
    BEF_AI_TOUCH_EVENT_MOVED,         // {zh} /< 触摸移动事件 {en} /< Touch move event
    BEF_AI_TOUCH_EVENT_STATIONARY,    // {zh} /< 触摸驻停事件 {en} /< Touch stop event
    BEF_AI_TOUCH_EVENT_ENDED,         // {zh} /< 触摸结束事件 {en} /< Touch end event
    BEF_AI_TOUCH_EVENT_CANCELLED,     // {zh} /< 触摸取消事件 {en} /< Touch cancel event
} bef_ai_touch_event_code;

typedef enum {
    BEF_AI_GESTURE_TAP,                 // {zh} /< 单击手势 {en} /< Click gesture
    BEF_AI_GESTURE_PAN,                 // {zh} /< 滑动手势 {en} /< Slide gesture
    BEF_AI_GESTURE_ROTATE,              // {zh} /< 旋转手势 {en} /< Rotation gesture
    BEF_AI_GESTURE_SCALE,               // {zh} /< 缩放手势 {en} /< Zoom gesture
    BEF_AI_GESTURE_LONG_PRESS,          // {zh} /< 长按手势 {en} /< Long press gesture
    BEF_AI_GESTURE_DOUBLE_CLICK         // {zh} /< 双击手势 {en} /< Double click gesture
} bef_ai_gesture_event_code;

typedef enum
{
    BEF_AI_TOUCH_BEGAN,         // {zh} /< 触摸开始事件 {en} /< Touch start event
    BEF_AI_TOUCH_MOVED,         // {zh} /< 触摸移动事件, deprecated {en} /< Touch movement event, deprecated
    BEF_AI_TOUCH_ENDED,         // {zh} /< 触摸结束事件 {en} /< Touch end event
    BEF_AI_TOUCH_CANCELLED,     // {zh} /< 触摸取消事件 {en} /< Touch cancel event
    BEF_AI_PAN,                 // {zh} /< 滑动手势 {en} /< Slide gesture
    BEF_AI_ROTATE,              // {zh} /< 旋转手势 {en} /< Rotation gesture
    BEF_AI_SCALE,               // {zh} /< 缩放手势 {en} /< Zoom gesture
    BEF_AI_LONG_PRESS,          // {zh} /< 长按手势 {en} /< Long press gesture
    BEF_AI_DOUBLE_CLICK         // {zh} /< 双击手势 {en} /< Double click gesture
} bef_ai_event_code;


typedef enum
{
    BEF_AI_AMAZING_TOUCH_BEGAN = 0,
    BEF_AI_AMAZING_TOUCH_MOVED = 1,
    BEF_AI_AMAZING_TOUCH_STATIONARY = 2,
    BEF_AI_AMAZING_TOUCH_ENDED = 3,
    BEF_AI_AMAZING_TOUCH_CANCELED = 4
}bef_ai_amazing_touch_type;

typedef char*(*bef_ai_resource_finder)(bef_effect_handle_t, const char *, const char *);


#define EFFECT_HAND_DETECT_DELAY_FRAME_COUNT 4


#endif
