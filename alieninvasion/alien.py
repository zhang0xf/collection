import pygame
from pygame.sprite import Sprite

class Alien(Sprite):
    """表示单个外星人的类"""
    def __init__(self,ai_settings,screen):
        """初始化外星人并设置其起始位置"""
        super(Alien,self).__init__()
        self.screen = screen
        self.screen_rect = screen.get_rect()
        self.ai_settings = ai_settings

        self.original_image = pygame.image.load('images/alien.bmp')
        self.original_rect = self.original_image.get_rect()
        # 设定缩放比例为屏幕宽度的百分比
        scale_factor = 0.05  # 例如：图片宽度 = 屏幕宽度 × 5%
        target_width = int(self.screen_rect.width * scale_factor)
        # 计算等比高度
        target_height = int(self.original_rect.height * (target_width / self.original_rect.width))
        # 缩放图像(保持长宽比)
        self.image = pygame.transform.scale(self.original_image, (target_width, target_height))
        self.rect = self.image.get_rect()

        # 每个外星人最初都在屏幕左上角附近￼
        self.rect.x = self.rect.width
        self.rect.y = self.rect.height
        # 存储外星人的准确位置(浮点数)
        self.x = float(self.rect.x)

    def blitme(self):
        """在指定位置绘制外星人"""
        self.screen.blit(self.image,self.rect)

    def check_edges(self):
        """如果外星人位于屏幕边缘,就返回True"""
        screen_rect = self.screen.get_rect()
        if self.rect.right >= screen_rect.right:
            return True
        elif self.rect.left <= 0:
            return True

    def update(self):
        """向左或向右移动外星人"""
        self.x+= (self.ai_settings.alien_speed_factor * self.ai_settings.fleet_direction)
        self.rect.x = self.x