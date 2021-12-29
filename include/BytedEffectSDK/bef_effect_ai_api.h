// Copyright (C) 2019 Beijing Bytedance Network Technology Co., Ltd.
#ifndef bef_effect_ai_api_h
#define bef_effect_ai_api_h

#include "bef_effect_ai_public_define.h"
#include "bef_effect_ai_face_detect.h"
#include "bef_effect_ai_hand.h"
#include "bef_effect_ai_skeleton.h"
#include "bef_effect_ai_face_attribute.h"

#if defined(__ANDROID__) || defined(TARGET_OS_ANDROID)
#include <jni.h>
#endif


/**
 * @brief Create effect handle.
 * @param handle      Effect handle that will be created.
 * @return            If succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h.
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_create(bef_effect_handle_t *handle);

/**
 * @param handle      Effect handle that will  destroy
 */
BEF_SDK_API void bef_effect_ai_destroy(bef_effect_handle_t handle);



/**
 * @brief Initialize effect handle.
 * @param handle     Effect handle
 * @param width      Texture width
 * @param height     Texture height
 * @param strModeDir  Resource folder
 * @return           If succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_init(bef_effect_handle_t handle, int width, int height, const char *strModeDir, const char* deviceName);


/**
 * should set imageMode = true while processing images with only faceMakeup sticker has been set
 * @param handle
 * @param imageMode
 * @return
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_image_mode(bef_effect_handle_t handle, bool imageMode);

/**
* @brief Return all available features name, can only be called after bef_effect_ai_init
* @return            If succeed return BEF_EFFECT_RESULT_SUC, `features` will contain all available feature name item, each item has length of BEF_EFFECT_FEATURE_LEN,
            `len` would point to a number which stands for the amount of features.
            BEF_RESULT_FAIL is returned if the given space is not big enough (according to `len`) to hold data returned by this api.
            BEF_RESULT_INVALID_EFFECT_HANDLE is returned if this api been called before `bef_effect_ai_init`.
*/
BEF_SDK_API bef_effect_result_t bef_effect_available_features(char (*features)[BEF_EFFECT_FEATURE_LEN], int* len);



/**
 * @brief Set camera toward
 * @param handle        Effect handle that  initialized
 * @param position      Camera positin
 * @return if succeed return IES_RESULT_SUC,  other value please see bef_effect_base_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_camera_device_position(bef_effect_handle_t handle,  bef_ai_camera_position position);


BEF_SDK_API bef_effect_result_t bef_effect_ai_set_device_rotation(bef_effect_handle_t handle, float* quaternion);

 /**
 * @brief Set frame size.
 * @param handle     Effect handle
 * @param width      Texture width
 * @param height     Texture height
 * @return           If succeed return BEF_EFFECT_RESULT_SUC,  other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_width_height(bef_effect_handle_t handle, int width, int height);


/**
 * @brief Set camera orientation, which is used for detection.
 * @param handle      Effect handle that  initialized
 * @param orientation  Camera clock wise
 * @return            if succeed return IES_RESULT_SUC,  other value please see bef_effect_base_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_orientation(bef_effect_handle_t handle, bef_ai_rotate_type orientation);

/**
 * @brief Setup beauty-face-filter with a specified string.
 * @param handle      Effect handle
 * @param strBeautyName The name of beauty will apply
 * @return            If succeed return BEF_EFFECT_RESULT_SUC,  other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_beauty(bef_effect_handle_t handle, const char *strBeautyName);

/**
 * @brief Setup beauty-face-filter with a specified string.
 * @param handle      Effect handle
 * @param strMakeupName The path of makeup resource will apply
 * @return            If succeed return BEF_EFFECT_RESULT_SUC,  other value please see bef_effect_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_buildin_makeup(bef_effect_handle_t handle, const char* strMakeupName);


/**
 * @brief Setup reshape-face-filter with a specified string.
 * @param handle          Effect handle
 * @param strPath    The absolute path of effect package.
 * @return                If succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_reshape_face(bef_effect_handle_t handle, const char *strPath);

/**
 * @brief Update reshape-face-filter parameters
 * @param handle          Effect handle
 * @param fIntensity      Filter intensity, range in [0.0, 1.0]
 * @return                if succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_update_reshape_face(bef_effect_handle_t handle, const float fIntensity);

/**
 * @brief Update reshape-face-filter parameters
 * @param handle          Effect handle
 * @param eyeIntensity    eye intensity, range in [0.0, 1.0]
  * @param cheekIntensity cheek intensity, range in [0.0, 1.0]
 * @return                if succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_update_reshape_face_intensity(bef_effect_handle_t handle, const float eyeIntensity, const float cheekIntensity);


/**
 @param handle              effect handle
 @param leftFilterPath current filter path
 @param rightFilterPath    next filter path
 @parm  direction           the direction that the next filter will appear
 @param position            the borderline of left-filter and right-filter in x-axis.
 @return            if succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_switch_color_filter_v2(bef_effect_handle_t handle, const char *leftFilterPath, const char *rightFilterPath, float position);
/**
 * Set color filter with a specified string.
 * @param handle    Effect handle
 * @param strPath   The absolute path of effect package.
 * @return          If succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_color_filter_v2(bef_effect_handle_t handle, const char *strPath);

/**
 * @brief Set effect with a specified string.
 * @param handle    Effect handle
 * @param strPath   The absolute path of effect package.
 * @return          If succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_effect(bef_effect_handle_t handle, const char *strPath);

/** {zh} 
 * @brief set composer resource path,
 * 设置composer资源包路径，使composer资源包生效
 * @param handle Effect Handle
 * @param strPath composer file path
 * @Deprecated
 */
/** {en} 
 * @brief Set composer resource path,
 * Set the composer resource package path to make the composer resource package effective
 * @param handle Effect Handle
 * @param strPath composer file path
 * @Deprecated
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_composer(bef_effect_handle_t handle, const char *strPath);

/** {zh} 
 * @brief set composer effect path array
 * 设置资源包路径数组,通过更新数组设置特效的组合
 * @param nodePaths 特效资源路径的数组
 * @param nodeNum 特效资源路径的数组长度
 *
 */
/** {en} 
 * @brief Set composer effect path array
 * Set the array of resource package paths, and set the combination of effects by updating the array
 * @param nodePaths Array of special effect resource paths
 * @param nodeNum Array length of special effect resource paths
 *
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_composer_set_nodes(bef_effect_handle_t handle, const char *nodePaths[], int nodeNum);

// {zh} / 设置资源包路径数组，可通过额外的 ndoeTags 设置附加信息 {en} /Set the array of resource package paths, additional information can be set through additional ndoeTags
// {zh} / @param handle 创建的 handle {en} /@Param handle created by handle
// {zh} / @param nodePaths 特效资源路径数组 {en} /@Param nodePaths effect resource path array
// {zh} / @param nodeTags 特效资源附加信息，与nodePaths 一一对应 {en} /@Param nodeTags special effects resource additional information, one-to-one correspondence with nodePaths
// {zh} / @param nodeNum 特效资源数组的长度 {en} /@Param nodeNum The length of the array of special effects resources
BEF_SDK_API bef_effect_result_t bef_effect_ai_composer_set_nodes_with_tags(bef_effect_handle_t handle, const char *nodePaths[], const char *nodeTags[], int nodeNum);

/** {zh} 
 * @brief append composer effect path array
 * 追加资源包路径数组,通过追加数组设置特效的组合
 * @param nodePaths 特效资源路径的数组
 * @param nodeNum 特效资源路径的数组长度
 *
 */
/** {en} 
 * @brief Append composer effect path array
 * append resource package path array, set the combination of special effects through append array
 * @param nodePaths array of special effect resource paths
 * @param nodeNum array length of special effect resource paths
 *
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_composer_append_nodes(bef_effect_handle_t handle, const char *nodePaths[], int nodeNum);
/** {zh} 
 * @brief append composer effect path array
 * 追加资源包路径数组,通过追加数组设置特效的组合
 * @param nodePaths 特效资源路径的数组
 * @param nodeTags 特效资源附加信息，与nodePaths 一一对应
 * @param nodeNum 特效资源路径的数组长度
 *
 */
/** {en} 
 * @brief Append composer effect path array
 * append resource package path array, set the combination of special effects through append array
 * @param nodePaths array of special effect resource paths
 * @param nodeTags additional information of special effect resources, one-to-one correspondence with nodePaths
 * @param nodeNum array length of special effect resource path
 *
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_composer_append_nodes_with_tags(bef_effect_handle_t handle, const char *nodePaths[], const char *nodeTags[], int nodeNum);

/** {zh} 
 * @brief remove composer effect path array
 * 删除资源包路径数组,通过删除数组设置特效的组合
 * @param nodePaths 特效资源路径的数组
 * @param nodeNum 特效资源路径的数组长度
 *
 */
/** {en} 
 * @brief Remove composer effect path array
 * Delete the resource package path array, set the combination of effects by deleting the array
 * @param nodePaths Array of special effect resource paths
 * @param nodeNum Array length of special effect resource paths
 *
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_composer_remove_nodes(bef_effect_handle_t handle, const char *nodePaths[], int nodeNum);

/** {zh} 
 * @brief set composer node intensity
 * 设置组合特效的单个节点的强度
 * @param handle Effect Handle
 * @param key 特效资源的路径
 * @param value 特效的强度
 */
/** {en} 
 * @brief Set composer node intensity
 * Set the intensity of a single node that combines effects
 * @param handle Effect Handle
 * @param key The path to the effect resource
 * @param value The intensity of the effect
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_composer_update_node(bef_effect_handle_t handle, const char *nodePath,const char *nodeTag, float value);

/** {zh} 
 * @brief 设置Composer模式
 * @param handle        Effect handle
 * @param mode          0: A槽区+B槽区模式（Composer Feature）, 1: A槽区+B槽区+C槽区模式（Composer下沉）
 * @param orderType     0: 按照zorder排序, 目前只支持0
 * @return              成功返回BEF_EFFECT_RESULT_SUC, 其它值参考bef_effect_define.h
 * @Deprecated
 */
/** {en} 
 * @brief Set Composer mode
 * @param handle        Effect handle
 * @param mode          0: A slot + B slot mode (Composer Feature), 1: A slot + B slot + C slot mode (Composer sink)
 * @param orderType     0: sorted by zorder, currently only 0 is supported
 * @return               successfully returned BEF_EFFECT_RESULT_SUC,  other values refer to bef_effect_define h
 * @Deprecated
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_composer_set_mode(bef_effect_handle_t handle, int mode, int orderType);

/**
 * @param handle          Effect handle
 * @param textureid_src   texture source
 * @return                if succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_algorithm_texture(bef_effect_handle_t handle, unsigned int textureid_src, double timeStamp);

/**
 * @param handle          Effect handle
 * @param texture         texture source
 * @param buffer          buffer address
 * @param buffer_format   format of buffer, see bef_ai_pixel_format
 * @param buffer_width    with of buffer
 * @param buffer_height   height of buffer
 * @param buffer_stride   stride of buffer
 * @param timeStamp       current time, unit second
 * @return                if succeed return BEF_EFFECT_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_algorithm_texture_with_buffer(bef_effect_handle_t handle,
                                                                            unsigned int texture,
                                                                            const unsigned char *buffer,
                                                                            bef_ai_pixel_format buffer_format,
                                                                            int buffer_width,
                                                                            int buffer_height,
                                                                            int buffer_stride,
                                                                            double timeStamp);

/** {zh} 
 * @param [in] handle Created effect handle
 *                    初始化的特效句柄，需要再OpenGL环境中使用
 * @param [in] img_in 数据buffer
 * @param [in] fmt_in 数据buffer的格式，支持RGBA,BGRA(ios支持）,NV21,NV12,YUV420P
 * @param [in] image_width 数据buffer图像的宽度
 * @param [in] image_height 数据buffer图像的长度
 * @param [in] image_stride 数据buffer的步长（一行的占用的字节数）
 * @param [in] timestamp     时间戳
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @param [In] handle Created effect handle
 *                    The initialized special effect handle needs to be used in the OpenGL environment
 * @param  [in] img_in data buffer
 * @param  [in] fmt_in the format of the data buffer, support RGBA, BGRA (ios support), NV21, NV12, YUV420P
 * @param  [in] image_width the width of the data buffer image
 * @param  [in] image_height the length of the data buffer image
 * @param  [in] image_stride the step size of the data buffer (the number of bytes occupied by a line)
 * @param  [in] timestamp timestamp
 * @return If succeed return BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define. H
 *          successfully return BEF_RESULT_SUC, fail to return the corresponding error code, please refer to bef_effect_ai_public_define for details
 */
BEF_SDK_API bef_effect_result_t
bef_effect_ai_algorithm_buffer(
                              bef_effect_handle_t handle,
                              const unsigned char *img_in,
                              bef_ai_pixel_format fmt_in,
                              int image_width,
                              int image_height,
                              int image_stride,
                              double timestamp
                              );

/**
 * @breif            Draw srcTexture with effects to dstTexture.
 * @param handle     Effect handle
 * @param srcTexture source texture
 * @param dstTexture distination texture
 * @return           if succeed return IES_RESULT_SUC,  other value please see bef_effect_base_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_process_texture(bef_effect_handle_t handle, unsigned int srcTexture, unsigned int dstTexture, double timeStamp);

/** {zh} 
 * @breif Draw source buffer with effects to destination buffer.
 *        绘制特效
 * @param [in] handle Created effect handle
 *                    初始化的特效句柄
 * @param [in] img_in 输入图片buffer
 * @param [in] fmt_in 输入图片buffer的格式，支持RGBA,BGRA（ios支持）,NV12,NV21,YUV420P
 * @param [in] image_width 输入图片buffer的宽度
 * @param [in] image_height 输入图片buffer的高度
 * @param [in] image_stride 输入图片buffer的步长（一行字节数）
 * @param [in] img_out 输出图片数据
 * @param [in] fmt_out 输出图片数据格式，支持RGBA,NV12,NV21,YUV420P
 * @param [in] timestamp   Current timestamp
 *                         时间戳
 * @return If succeed return BEF_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @breif Draw source buffer with effects to destination buffer.
 *        Draw special effects
 * @param  [in] handle Created effect handle
 *                    initialized special effects handle
 * @param  [in] img_in input picture buffer
 * @param  [in] fmt_in input picture buffer format, support RGBA, BGRA (ios support), NV12, NV21, YUV420P
 * @param  [in] image_width input picture buffer width
 * @param  [in] image_height input picture buffer Height
 * @param  [in] image_stride input picture buffer step size (number of bytes per line)
 * @param  [in] img_out output picture data
 * @param  [in] fmt_out output picture data format, support RGBA, NV12, NV21, YUV420P
 * @param  [in] timestamp Current timestamp
 *                         timestamp
 * @return If succeed return BEF_RESULT_SUC, other values please see bef_effect_ai_public_define h
 *          successfully return BEF_RESULT_SUC, fail to return the corresponding error code, please refer to bef_effect_ai_public_define for details
 */
BEF_SDK_API bef_effect_result_t
bef_effect_ai_process_buffer(bef_effect_handle_t handle,
                            const unsigned char *img_in,
                            bef_ai_pixel_format fmt_in,
                            int image_width,
                            int image_height,
                            int image_stride,
                            unsigned char *img_out,
                            bef_ai_pixel_format fmt_out,
                            double timestamp
                            );

/**
 * @param handle      Effect handle that will be created
 * @param fIntensity  Filter smooth intensity, range in [0.0, 1.0]
 * if fIntensity is 0 , this filter would not work.
 * @return            if succeed return BEF_EFFECT_RESULT_SUC,  other value please see bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_intensity(bef_effect_handle_t handle, bef_intensity_type intensityType, float fIntensity);

/** {zh} 
 * @brief 开启或关闭并行框架，开启后算法在独立线程完成检测。默认不开启
 * @param handle effect handle
 * @param usePipeline 控制参数
 */
/** {en} 
 * @brief Enables or closes the parallel framework, and the algorithm completes detection in a separate thread after opening. The default does not open
 * @param handle effect handle
 * @param usePipeline  control parameters
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_use_pipeline_processor(bef_effect_handle_t handle, bool usePipeline);

/** {zh} 
* @brief 清理并行框架残余算法任务，在切后台、切换分辨率或切相机时使用。总之画面会不连续出现的时候都应该调用
* @param handle     Effect handle
*//** {en} 
* @brief Clean up the remnant algorithm tasks of the parallel framework, used when cutting the background, switching resolutions, or cutting the camera. In short, the picture will appear discontinuously when you should call
* @param handle     Effect handle
*/
BEF_SDK_API bef_effect_result_t bef_effect_ai_clean_pipeline_processor_task(bef_effect_handle_t handle);

/** {zh} 
 * @brief 开启并行框架3buffer策略，避免 buffer 的拷贝
 * @param handle effect handle
 * @param use3Buffer 是否开启3buffer
 */
/** {en} 
 * @brief Enable the parallel framework 3buffer policy to avoid copying buffer
 * @param handle effect handle
 * @param use3Buffer Whether to open 3buffer
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_use_3buffer(bef_effect_handle_t handle, bool use3buffer);

/** {zh} 
 * @brief 获取人脸检测结果
 * @param handle 已创建的授权
 * @param result 人脸检测结果
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 授权码非法返回BEF_RESULT_INVALID_LICENSE，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Get the face detection result
 * @param handle created authorization
 * @param result face detection result
 * @return If succeed return BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define h
 *         successfully return BEF_RESULT_SUC, the authorization code illegally returns BEF_RESULT_INVALID_LICENSE, other failures return the corresponding error code, please refer to bef_effect_ai_public_define for details.
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_get_face_detect_result(bef_effect_handle_t handle, bef_ai_face_info* result);


/** {zh} 
 * @brief 获取人脸检测mask结果
 * @param handle 已创建的授权
 * @param mask_type mask类型枚举值， bef_face_mask_type
 * @param result 人脸检测mask结果，根据类型输入
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 授权码非法返回BEF_RESULT_INVALID_LICENSE，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Get the face detection mask result
 * @param handle The created authorization
 * @param mask_type mask type enumeration value, bef_face_mask_type
 * @param result Face detection mask result, enter
 * @return If succeed return BEF_RESULT_SUC according to the type, other values please refer to bef_effect_ai_public_define h
 *         Successfully return BEF_RESULT_SUC, the authorization code illegally returns BEF_RESULT_INVALID_LICENSE, and other failures return the corresponding error code, please refer to bef_effect_ai_public_define for details.
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_get_face_seg_result(bef_effect_handle_t handle, int mask_type, void* result);


/** {zh} 
 * @brief 获取手的检测结果
 * @param handle 已创建的授权
 * @param result 手检测结果
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 授权码非法返回BEF_RESULT_INVALID_LICENSE，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Get the detection result of the hand
 * @param handle  the authorization created
 * @param result  the hand detection result
 * @return If succeed returns BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define h
 *          successfully returns BEF_RESULT_SUC, the authorization code illegally returns BEF_RESULT_INVALID_LICENSE, and other failures return the corresponding error code, please refer to bef_effect_ai_public_define for details.
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_get_hand_detect_result(bef_effect_handle_t handle, bef_ai_hand_info *result);

/** {zh} 
 * @brief 获取人体检测结果
 * @param handle 已创建的授权
 * @param result 人体检测结果
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 授权码非法返回BEF_RESULT_INVALID_LICENSE，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Get the human body detection result
 * @param handle  the authorization created
 * @param result human body detection result
 * @return If succeed return BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define h
 *         successfully return BEF_RESULT_SUC, the authorization code illegally returns BEF_RESULT_INVALID_LICENSE, other failures return the corresponding error code, please refer to bef_effect_ai_public_define.
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_get_skeleton_detect_result(bef_effect_handle_t handle, bef_ai_skeleton_result *result);

/** {zh} 
 * @brief 获取人脸属性检测结果
 * @param handle 已创建的授权
 * @param result 人脸属性检测结果
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 授权码非法返回BEF_RESULT_INVALID_LICENSE，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Get the face attribute detection result
 * @param handle created authorization
 * @param result face attribute detection result
 * @return If succeed return BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define h
 *         successfully return BEF_RESULT_SUC, the authorization code illegally returns BEF_RESULT_INVALID_LICENSE, other failures return the corresponding error code, please refer to bef_effect_ai_public_define.
 */
BEF_SDK_API bef_effect_result_t bef_effect_ai_get_face_attr_detect_result(bef_effect_handle_t handle, bef_ai_face_attribute_result *result);



/** {zh} 
* @brief 给贴纸发送消息
* @param handle 已创建的授权
* @param msgID 消息id
* @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
*         成功返回 BEF_RESULT_SUC, 授权码非法返回BEF_RESULT_INVALID_LICENSE，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
*//** {en} 
* @brief Send a message to the sticker
* @param handle created authorization
* @param msgID message id
* @return If succeed return BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define h
*         successfully return BEF_RESULT_SUC, the authorization code illegally returns BEF_RESULT_INVALID_LICENSE, other failures return the corresponding error code, please refer to bef_effect_ai_public_define for details.
*/
BEF_SDK_API bef_effect_result_t bef_effect_ai_send_msg(bef_effect_handle_t handle, unsigned int msgID, long arg1, long arg2, const char *arg3);


/** {zh} 
* @brief 给贴纸发送开拍重置信息，这个函数目前仅用在使用creator
*        设计的贴纸，并且确认勾选了开拍重置选项
* @param handle 已创建的授权
* @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
*         成功返回 BEF_RESULT_SUC, 授权码非法返回BEF_RESULT_INVALID_LICENSE，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
*//** {en} 
* @brief Send the start shot reset information to the sticker. This function is currently only used for stickers designed by creator
*        , and confirm that the start shot reset option
* @param handle  has been checked
* @return If succeed returns BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define. H
*          successfully returns BEF_RESULT_SUC, the authorization code returns BEF_RESULT_INVALID_LICENSE illegally, and other failures return the corresponding error code, please refer to bef_effect_ai_public_define for details.
*/
BEF_SDK_API bef_effect_result_t bef_effect_ai_reset_sticker(bef_effect_handle_t handle);

// {zh} / @brief 处理触摸事件 {en} Handle touch events briefly
// {zh} / @param handle 已创建的句柄 {en} /@Param handle created handle
// {zh} / @param event 触摸事件类型 {en} /@param event touch event type
// {zh} / @param x 触摸位置 {en} @Param x touch position
// {zh} / @param y 触摸位置 {en} @Param y touch position
// {zh} / @param force 压力值 {en} @Param force
// {zh} / @param majorRadius 触摸范围 {en} @param majorRadius touch range
// {zh} / @param pointerId 触摸点id {en} /@param pointerId touch point id
// {zh} / @param pointerCount 触摸点数量 {en} @param pointerCount number of touch points
BEF_SDK_API bef_effect_result_t bef_effect_ai_process_touch(bef_effect_handle_t handle, bef_ai_touch_event_code event, float x, float y, float force, float majorRadius, int pointerId, int pointerCount);

// {zh} / @brief 处理手势事件 {en} Handle gesture events briefly
// {zh} / @param handle 已创建的句柄 {en} /@Param handle created handle
// {zh} / @param gesture 手势类型 {en} @param gesture type
// {zh} / @param x 触摸位置，缩放手势表示缩放比例，旋转手势表示旋转角度 {en} /@Param x touch position, zoom gesture indicates zoom scale, rotation gesture indicates rotation angle
// {zh} / @param y 触摸位置 {en} @Param y touch position
// {zh} / @param dx 移动距离 {en} @Param dx moving distance
// {zh} / @param dy 移动距离 {en} @Param dy moving distance
// {zh} / @param factor 缩放因数 {en} /@param factor scaling factor
BEF_SDK_API bef_effect_result_t bef_effect_ai_process_gesture(bef_effect_handle_t handle, bef_ai_gesture_event_code gesture, float x, float y, float dx, float dy, float factor);

// {zh} / @brief 通过 buffer 设置 render cache texture {en} /@Brief render cache texture through buffer settings
// {zh} / @details 传入一个固定名字的纹理给到 SDK，传入一个 buffer，SDK 会将其解析成纹理 {en} /@details Pass in a texture with a fixed name to the SDK, pass in a buffer, and the SDK will parse it into a texture
// {zh} / @param handle 句柄 {en} /@param handle
// {zh} / @param key 纹理名称 {en} /@param key texture name
// {zh} / @param image 图像数据 {en} @param image image data
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_render_cache_texture_with_buffer(bef_effect_handle_t handle, const char* key, bef_ai_image* image);

// {zh} / @brief 通过文件设置 render cache texture {en} /@Brief render cache texture through file settings
// {zh} / @details 传入一个固定名字的纹理给到 SDK，传入一个文件路径，SDK 会将其解析成纹理 {en} /@details Pass in a texture with a fixed name to the SDK, pass in a file path, and the SDK will parse it into a texture
// {zh} / @param handle 句柄 {en} /@param handle
// {zh} / @param key 纹理名称 {en} /@param key texture name
// {zh} / @param path 文件绝对路径 {en} /@param path file absolute path
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_render_cache_texture(bef_effect_handle_t handle, const char* key, const char* path);

// {zh} / @brief 设置 gles 版本 {en} /@brief set gles version
// {zh} / @details 需要在初始化之前调用才有效果 {en} /@details need to be called before initialization to have effect
// {zh} / @param handle 句柄 {en} /@param handle
// {zh} / @param api gles 版本，参见 bef_ai_render_api_type {en} /@param api gles version, see bef_ai_render_api_type
BEF_SDK_API bef_effect_result_t bef_effect_ai_set_render_api(bef_effect_handle_t handle, bef_ai_render_api_type api);

// {zh} / @brief 是否使用内置传感器 {en} /@Brief Whether to use built-in sensors
// {zh} / @param handle 句柄 {en} /@param handle
// {zh} / @param useBuiltinSensor 是否使用内置传感器 {en} /@Param useBuiltinSensor Whether to use built-in sensors
BEF_SDK_API bef_effect_result_t bef_effect_ai_use_builtin_sensor(bef_effect_handle_t handle, bool useBuiltinSensor);

// {zh} / @brief 在一定时间内加载素材 {en} /@Brief Load material within a certain time
// {zh} / @param handle 句柄 {en} /@param handle
// {zh} / @param timeout 等待时间，单位 us，-1 时表示一直等待直到素材加载完成 {en} /@Param timeout waiting time, unit us, -1 means waiting until the material is loaded
BEF_SDK_API bef_effect_result_t bef_effect_ai_load_resource_with_timeout(bef_effect_handle_t handle, int timeout);

#ifdef __ANDROID__
/** {zh} 
 * @param handle Created effect detect handle
 *                   已创建的句柄
 * @param result Current face detect result struct
 *
 */
/** {en} 
 * @param Handle Created effect detect handle
 *                   Created handle
 * @param result Current face detect result struct
 *
 */
BEF_SDK_API bef_effect_result_t
bef_effect_ai_check_license(
                           JNIEnv* env,
                           jobject context,
                           bef_effect_handle_t handle,
                           const char *licensePath
                           );

BEF_SDK_API bef_effect_result_t
bef_effect_ai_check_license_buffer(
                           JNIEnv* env,
                           jobject context,
                           bef_effect_handle_t handle,
                           const char *buffer,
                           unsigned long buffer_len
                           );
#else
BEF_SDK_API bef_effect_result_t
bef_effect_ai_check_license(
                           bef_effect_handle_t handle,
                           const char *licensePath
                           );

BEF_SDK_API bef_effect_result_t
bef_effect_ai_check_license_buffer(
                           bef_effect_handle_t handle,
                           const char *buffer,
                           unsigned long buffer_len
                           );
#endif


BEF_SDK_API bef_effect_result_t
bef_effect_ai_check_online_license(bef_effect_handle_t handle, const char *licensePath);

#endif /* bef_effect_ai_h */
