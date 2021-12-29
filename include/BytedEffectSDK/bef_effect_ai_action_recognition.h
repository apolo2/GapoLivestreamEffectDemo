// Copyright (C) 2019 Beijing Bytedance Network Technology Co., Ltd.
#ifndef BEF_EFFECT_AI_ACTION_RECOGNITION_H
#define BEF_EFFECT_AI_ACTION_RECOGNITION_H

#include "bef_effect_ai_public_define.h"

#if defined(__ANDROID__) || defined(TARGET_OS_ANDROID)
#include<jni.h>
#endif

#define BEF_AI_ACTION_RECOGNITION_MAX_POINT_NUM 18

//  {zh} 反馈的身体部位类别  {en} Feedback by body part category
typedef enum {
    BEF_AI_ACTION_RECOGNITION_FeedbackNone = 0,
    BEF_AI_ACTION_RECOGNITION_FeedbackLeftArm = 1,//  {zh} 左臂  {en} Left arm
    BEF_AI_ACTION_RECOGNITION_FeedbackRightArm = 2, //  {zh} 右臂  {en} Right arm
    BEF_AI_ACTION_RECOGNITION_FeedbackLeftLeg = 3, //  {zh} 左腿  {en} Left leg
    BEF_AI_ACTION_RECOGNITION_FeedbackRightLeg = 4, //  {zh} 右腿  {en} Right leg
} bef_ai_action_recognition_feedback_body_part;

//  {zh} 初始姿态类别  {en} Initial attitude category
typedef enum {
    BEF_AI_ACTION_RECOGNITION_Stand = 1, // {zh} 站立 {en} Stand
    BEF_AI_ACTION_RECOGNITION_Lying = 2, // {zh} 平躺 {en} Lie flat
    BEF_AI_ACTION_RECOGNITION_Sitting = 3 // {zh} 坐姿 {en} Sitting posture
} bef_ai_action_recognition_start_pose_type;

// {zh} 动作计数结果信息 {en} Action counting result information
typedef struct bef_ai_action_recognition_result_st {
    bef_ai_tt_key_point keypoints[BEF_AI_ACTION_RECOGNITION_MAX_POINT_NUM]; //  {zh} 检测到的骨骼信息  {en} Bone information detected
    bef_ai_action_recognition_feedback_body_part feed_body_part;  //  {zh} 反馈的身体部位类别  {en} Feedback by body part category
    bef_ai_tt_key_point feedback_keypoints[BEF_AI_ACTION_RECOGNITION_MAX_POINT_NUM*2]; //  {zh} 检测到的反馈骨骼信息  {en} Feedback bone information detected
    int feedback_kp_count;  //  {zh} 检测到的反馈骨骼信息数量，feedback_keypoints的实际长度  {en} Number of feedback bones detected, actual length of feedback_keypoints
    bool recognize_succeed; //  {zh} 是否计数成功，为true时，表示计数成功，界面可以增加计数  {en} Whether the count is successful or not, when it is true, it means that the count is successful, and the interface can increase the count
    bool is_feedback_valid; //  {zh} 反馈信息是否有效，为true时，表示信息有效，界面可以显示反馈信息  {en} Whether the feedback information is valid or not, when it is true, it means that the information is valid, and the interface can display the feedback information
    
} bef_ai_action_recognition_result;

// {zh} 初始姿态检测结果信息 {en} Initial attitude detection result information
typedef struct bef_ai_action_recognition_start_pose_result_st {
    bool is_detected; //  {zh} 是否通过初始姿态检测，为true时，表示通过检测，可以开始计数  {en} Whether the initial attitude detection is passed, when true, it means that the detection is passed and the count can be started
} bef_ai_action_recognition_start_pose_result;

/** {zh} 
 * @brief 创建动作识别的句柄
 * @param [in] model_path 模型文件路径
 * @param [out] handle    Created action_recognition handle
 *                        创建的动作识别句柄
 * @return If succeed return BEF_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Create a handle for action recognition
 * @param  [in] model_path model file path
 * @param  [out] handle Created action_recognition handle
 *                         created action recognition handle
 * @return If succeed return BEF_RESULT_SUC, other values please see bef_effect_ai_public_define h
 *         Successfully return BEF_RESULT_SUC, fail to return the corresponding error code, please refer to bef_effect_ai_public_define for details
 */
BEF_SDK_API bef_effect_result_t
bef_effect_ai_action_recognition_create(
                             const char *model_path,
                             bef_effect_handle_t *handle
                             );

/** {zh} 
 * @param [in] handle Destroy the created action_recognition handle
 *                    销毁创建的动作识别句柄
 */
/** {en} 
 * @param [In] handle Destroy the created action_recognition handle
 *                    Destroy the created action recognition handle
 */
BEF_SDK_API void
bef_effect_ai_action_recognition_destroy(
                              bef_effect_handle_t handle
                              );

/** {zh} 
 * @brief 设置动作识别模板
 * @param [in] handle    Created action_recognition handle
 *                        已创建的动作识别句柄
 * @param [in] template_path 模板文件路径
 
 * @return If succeed return BEF_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Set the action recognition template
 * @param  [in] handle Created action_recognition handle
 *                         created action recognition handle
 * @param  [in] template_path template file path
 
 * @return If succeed returns BEF_RESULT_SUC, other values please see bef_effect_ai_public_define h
 *          successfully returns BEF_RESULT_SUC, fails to return the corresponding error code, please refer to bef_effect_ai_public_define for details
 */
BEF_SDK_API bef_effect_result_t
bef_effect_ai_action_recognition_set_template(bef_effect_handle_t handle, const char *template_path);

/** {zh} 
 * @brief 动作识别开始姿态检测
 * @param [in] handle Created action_recognition handle
 *                    已创建的骨骼句柄
 * @param [in] image Image base address
 *                   输入图片的数据指针
 * @param [in] pixel_format Pixel format of input image
 *                          输入图片的格式
 * @param [in] image_width  Image width
 *                          输入图像的宽度 (以像素为单位)
 * @param [in] image_height Image height
 *                          输入图像的高度 (以像素为单位)
 * @param [in] image_stride Image stride in each row
 *                          输入图像每一行的步长 (以像素为单位)
 * @param [in] orientation  Image orientation
 *                          输入图像的转向，具体请参考 bef_effect_ai_public_define.h 中的 bef_rotate_type
 * @param [in] type pose type  姿势类型
 * @param [in, out] is_detected   detection result 检测结果
 * @return If succeed return BEF_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Action recognition starts gesture detection
 * @param  [in] Handle Created action_recognition handle
 *                    Created skeleton handle
 * @param  [in] Image base address
 *                   Data pointer of the input image
 * @param  [in] pixel_format Pixel format of input image
 *                          Format of the input image
 * @param  [in] image_width Image width
 *                          Width of the input image in pixels
 * @param  [in] image_height Image height
 *                          Height of the input image in pixels
 * @param  [in] image_stride Image stride in each row
 *                          Step size of each row of the input image in pixels
 * @param  [in] orientation Image orientation
 *                          Turn of the input image, please refer to the bef_rotate_type in bef_effect_ai_public_define h
 * @param  [in] type pose type
 * @param  [in, out] is_detected detection result
 * @return If succeed return BEF_RESULT_SUC, other values please see bef_effect_ai_public_define h
 *         Successful return BEF_RESULT_SUC, failure return the corresponding error code, please refer to bef_effect_ai_public_define h
 */
BEF_SDK_API bef_effect_result_t
bef_effect_ai_action_recognition_start_pose_detect(
                                                   bef_effect_handle_t handle,
                                                   const unsigned char *image,
                                                   bef_ai_pixel_format pixel_format,
                                                   int image_width,
                                                   int image_height,
                                                   int image_stride,
                                                   bef_ai_rotate_type orientation,
                                                   bef_ai_action_recognition_start_pose_type type,
                                                   bef_ai_action_recognition_start_pose_result* result);

/** {zh} 
 * @brief 动作识别计数
 * @param [in] handle Created action_recognition handle
 *                    已创建的骨骼句柄
 * @param [in] image Image base address
 *                   输入图片的数据指针
 * @param [in] pixel_format Pixel format of input image
 *                          输入图片的格式
 * @param [in] image_width  Image width
 *                          输入图像的宽度 (以像素为单位)
 * @param [in] image_height Image height
 *                          输入图像的高度 (以像素为单位)
 * @param [in] image_stride Image stride in each row
 *                          输入图像每一行的步长 (以像素为单位)
 * @param [in] confirm_time  count confirmation time
 *                          计数确认时长
 * @param [in] orientation  Image orientation
 *                          输入图像的转向，具体请参考 bef_effect_ai_public_define.h 中的 bef_rotate_type
 * @param [in, out] action_recognition_result  不可为nullptr
 * @return If succeed return BEF_RESULT_SUC, other value please see bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Action recognition count
 * @param  [in] Handle Created action_recognition handle
 *                    Created skeleton handle
 * @param  [in] Image Image base address
 *                   Data pointer of input image
 * @param  [in] pixel_format Pixel format of input image
 *                          Format of input image
 * @param  [in] image_width Image width
 *                          Width of input image in pixels
 * @param  [in] image_height Image height
 *                          Height of input image in pixels
 * @param  [in] image_stride Image stride in each row
 *                          Step size of each row of input image in pixels
 * @param  [in] nconfirm_time\ count confirmation time Count confirmation time
 *                           [in]
 * @param orientation Image orientation Turn of input image, please refer to bef_rotate_type in bef_effect_ai_public_define h
 *                           [in,
 * @param out] action_recognition_result cannot return BEF_RESULT_SUC for nullptr If
 * @return succeed, other values please see bef_effect_ai_public_define h Successfully return BEF_RESULT_SUC, fail to return the corresponding error code, please refer to bef_effect_ai_public_define for details
 *         成功返回 BEF_RESULT_SUC, 失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
BEF_SDK_API bef_effect_result_t
bef_effect_ai_action_recognition_count(
                             bef_effect_handle_t handle,
                             const unsigned char *image,
                             bef_ai_pixel_format pixel_format,
                             int image_width,
                             int image_height,
                             int image_stride,
                             bef_ai_rotate_type orientation,
                             int confirm_time,
                             bef_ai_action_recognition_result *action_recognition_result
                             );

/** {zh} 
 * @brief 人体关键点授权
 * @param [in] handle Created action_recognition handle
 *                    已创建的动作识别句柄
 * @param [in] license 授权文件字符串
 * @param [in] length  授权文件字符串长度
 * @return If succeed return BEF_RESULT_SUC, other value please refer bef_effect_ai_public_define.h
 *         成功返回 BEF_RESULT_SUC, 授权码非法返回 BEF_RESULT_INVALID_LICENSE ，其它失败返回相应错误码, 具体请参考 bef_effect_ai_public_define.h
 */
/** {en} 
 * @brief Human body key point authorization
 * @param  [in] handle Created action_recognition handle
 *                    created action recognition handle
 * @param  [in] license authorization file character string
 * @param  [in] length authorization file character string length
 * @return If succeed returns BEF_RESULT_SUC, other values please refer to bef_effect_ai_public_define h
 *         successfully returns BEF_RESULT_SUC, authorization code illegally returns BEF_RESULT_INVALID_LICENSE, other failures return corresponding error codes, please refer to bef_effect_ai_public_define for details.
 */

#if defined(__ANDROID__) || defined(TARGET_OS_ANDROID)
BEF_SDK_API bef_effect_result_t bef_effect_ai_action_recognition_check_license(JNIEnv* env, jobject context, bef_effect_handle_t handle, const char *licensePath);
#else
#ifdef __APPLE__
BEF_SDK_API bef_effect_result_t bef_effect_ai_action_recognition_check_license(bef_effect_handle_t handle, const char *licensePath);
#endif
#endif

BEF_SDK_API bef_effect_result_t
bef_effect_ai_action_recognition_check_online_license(bef_effect_handle_t handle, const char *licensePath);


#endif // BEF_EFFECT_AI_ACTION_RECOGNITION_H

