//
//  LKADConfigModel.h
//  LKADSDK
//
//  Created by 兵伍 on 2019/3/15.
//  Copyright © 2019 兵伍. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface LKADConfigModel : NSObject
// 渠道标示（必填）
@property (nonatomic, strong) NSString *appId;
// 接入方App用户id
@property (nonatomic, strong) NSString *thirdUserId;
// 主颜色 （默认：#da3d33）
@property (nonatomic, strong) UIColor *mainTintColor;
// 下拉刷新个数提示背景色（默认：主颜色）
@property (nonatomic, strong) UIColor *pullRefreshTipBackColor;
// 下拉刷新个数提示文案（默认：推荐了%ld条更新），例如，推荐引擎为您推荐了%ld条更新
@property (nonatomic, copy) NSString *pullRefreshTipText;
// feed流关键词过滤
@property (nonatomic, strong) NSSet *feedFilter;
// toast 提示（方便调试）
@property (nonatomic, assign) BOOL enableToastLog;
// 开启测试环境（默认NO）
@property (nonatomic, assign) BOOL enableTestEnv;
// 自定义倒计时类
@property (nonatomic, strong) Class CustomCountDownViewClass;

/****************************** 倒计时UI *************************/

// 倒计时视图的背景色
@property (nonatomic, strong) UIColor *countDownViewBackgroundColor;
// 倒计时视图的圆圈颜色
@property (nonatomic, strong) UIColor *countDownViewCircleColor;
// 倒计时视图的文字颜色
@property (nonatomic, strong) UIColor *countDownViewTextColor;
// 倒计时视图的文字字体
@property (nonatomic, strong) UIFont *countDownViewTextFont;

@end


