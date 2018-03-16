//
//  QuickDatePickerView.h
//  QuickDatePickerView
//
//  Created by pcjbird on 2018/3/15.
//  Copyright © 2018年 Zero Status. All rights reserved.
//

#import <UIKit/UIKit.h>

//! Project version number for QuickDatePickerView.
FOUNDATION_EXPORT double QuickDatePickerViewVersionNumber;

//! Project version string for QuickDatePickerView.
FOUNDATION_EXPORT const unsigned char QuickDatePickerViewVersionString[];

// In this header, you should import all the public headers of your framework using statements like #import <QuickDatePickerView/PublicHeader.h>


/**
 *  日期样式
 */
typedef enum{
    QuickDateStyle_YearMonthDayHourMinute = 0, //年月日时分
    QuickDateStyle_MonthDayHourMinute = 1,     //月日时分
    QuickDateStyle_YearMonthDay = 2,           //年月日
    QuickDateStyle_YearMonth = 3,              //年月日
    QuickDateStyle_MonthDay = 4,               //月日
    QuickDateStyle_HourMinute = 5,             //时分
    
}QuickDateStyle;


/**
 * @brief 日期选择器结果回调block
 */
typedef void(^QuickDatePickerViewBlock)(NSDate * date);

/**
 * @brief 日期选择器
 */
@interface QuickDatePickerView : UIView

/**
 * @brief 确定按钮背景颜色
 */
@property (nonatomic, strong) UIColor *doneButtonColor;

/**
 * @brief 确定按钮标题
 */
@property (nonatomic, strong) NSString *doneButtonTitle;


/**
 * @brief 是否显示灰色背景蒙版
 */
@property (nonatomic, assign) BOOL grayMaskBack;

/**
 * @brief 是否圆角显示
 */
@property (nonatomic, assign) BOOL roundCorner;

/**
 * @brief 滚轮日期颜色(默认黑色)
 */
@property (nonatomic,strong)UIColor *datePickerColor;

/**
 * @brief 限制最大时间（默认2099）datePicker大于最大日期则滚动回最大限制日期
 */
@property (nonatomic, retain) NSDate *maxLimitDate;
/**
 * @brief 限制最小时间（默认0） datePicker小于最小日期则滚动回最小限制日期
 */
@property (nonatomic, retain) NSDate *minLimitDate;

/**
 * @brief 大号年份字体颜色(默认灰色)想隐藏可以设置为clearColor
 */
@property (nonatomic, retain) UIColor *yearLabelColor;

/**
 * @brief 隐藏背景年份文字
 */
@property (nonatomic, assign) BOOL hideBackgroundYearLabel;

/**
 *@brief 初始化，默认滚动到当前时间
 *@param dateStyle 样式
 *@param complete  选择回调
 */
-(instancetype)initWithDateStyle:(QuickDateStyle)dateStyle complete:(QuickDatePickerViewBlock)complete;

/**
 *@brief 初始化，滚动到指定的日期
 *@param dateStyle 样式
 *@param date 滚动到的指定的日期
 *@param complete  选择回调
 */
-(instancetype)initWithDateStyle:(QuickDateStyle)dateStyle scrollTo:(NSDate *)date complete:(QuickDatePickerViewBlock)complete;


/**
 * @brief 显示日期选择器
 */
-(void)show;
@end
