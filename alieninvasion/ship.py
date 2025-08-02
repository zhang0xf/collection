import pygame
from pygame.sprite import Sprite

class Ship(Sprite):
    def __init__(self,ai_settings,screen):
        """初始化飞船并设置其初始位置"""
        super(Ship,self).__init__()
        self.screen = screen
        self.screen_rect = screen.get_rect()
        self.ai_settings = ai_settings

        # 加载飞船图像并获取其外接矩形
        self.original_image = pygame.image.load('images/ship.bmp')
        self.original_rect = self.original_image.get_rect()
        # 设定缩放比例为屏幕宽度的百分比（可调整）
        scale_factor = 0.08  # 例如：图片宽度 = 屏幕宽度 × 8%
        target_width = int(self.screen_rect.width * scale_factor)
        # 计算等比高度
        target_height = int(self.original_rect.height * (target_width / self.original_rect.width))
        # 缩放图像(保持长宽比)
        self.image = pygame.transform.scale(self.original_image, (target_width, target_height))
        
        self.rect = self.image.get_rect()
        self.screen_rect = screen.get_rect()
        # 将每艘新飞船放在屏幕底部中央(要将游戏元素居中，可设置相应rect对象的属性center、centerx或centery)
        self.rect.centerx = self.screen_rect.centerx
        self.rect.bottom = self.screen_rect.bottom

        # 在飞船的属性center中存储小数值
        self.center = float(self.rect.centerx)

        # 移动标志
        self.moving_right = False
        self.moving_left = False

    def update(self):
        """根据移动标志调整飞船的位置"""
        # 如果玩家同时按下了左右箭头键，将先增大飞船的rect.centerx值，再降低这个值，即飞船的位置保持不变
        # 如果使用一个elif代码块来处理向左移动的情况，右箭头键将始终处于优先地位
        if self.moving_right and self.rect.right < self.screen_rect.right:
            self.center += self.ai_settings.ship_speed_factor
        if self.moving_left and self.rect.left > 0:
            self.center -= self.ai_settings.ship_speed_factor
        # 根据self.center更新rect对象
        # self.rect.centerx将只存储self.center的整数部分
        self.rect.centerx = self.center # 移动的单位为像素(表面上设置的是位置，实际上反映的是速度，因为“每帧更新”)

    def blitme(self):
        """在指定位置绘制飞船"""
        self.screen.blit(self.image,self.rect)

    def center_ship(self):
        """让飞船在屏幕上居中"""
        self.center = self.screen_rect.centerx