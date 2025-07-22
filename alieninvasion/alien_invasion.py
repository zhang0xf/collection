import pygame
from pygame.sprite import Group
from settings import Settings
from game_stats import GameStats
from ship import Ship
import game_functions as gf
from button import Button
from scoreboard import Scoreboard

def run_game():
    pygame.init()
    ai_settings = Settings()
    # 对象screen是一个surface。在Pygame中，surface是屏幕的一部分，用于显示游戏元素
    screen = pygame.display.set_mode((ai_settings.screen_width,ai_settings.screen_height))
    pygame.display.set_caption("Alien Invasion")
    play_button = Button(ai_settings,screen,"Play")
    stats = GameStats(ai_settings)
    sb = Scoreboard(ai_settings,screen,stats)
    ship = Ship(ai_settings,screen)
    bullets = Group() # 编组
    aliens = Group()
    gf.create_fleet(ai_settings,screen,ship,aliens) # 创建外星人群

    # 游戏主循环
    while True:
        gf.check_events(ai_settings, screen, stats, sb, play_button, ship, aliens, bullets)
        if stats.game_active:
            ship.update()
            bullets.update() # 当你对编组调用update()时，编组将自动对其中的每个精灵调用update()
            gf.update_bullets(ai_settings, screen, stats, sb, ship, aliens, bullets)
            gf.update_aliens(ai_settings, stats, sb, screen, ship, aliens, bullets)
        gf.update_screen(ai_settings, screen, stats, sb, ship, aliens, bullets, play_button)

run_game()