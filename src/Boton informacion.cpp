#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        // 
        if (!MenuLayer::init()) return false;

        //
        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            
            //
            auto discordSprite = CCSprite::create("DiscordGDPS.png");

            //
            if (!discordSprite) {
                discordSprite = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
            }

            //
            auto discordBtn = CCMenuItemSpriteExtra::create(
                discordSprite,
                this,
                menu_selector(MyMenuLayer::onDiscordClick)
            );

            // :v
            discordBtn->setID("discord-button-gdps");
            bottomMenu->addChild(discordBtn);

            // dos puntos uve
            bottomMenu->updateLayout();
        }

        return true;
    }

    // Que haces aqui?
    void onDiscordClick(CCObject* sender) {
        //Link de discord :D
        
        utils::web::openLinkInBrowser("https://discord.gg/bzS2cmCGt4");

        // Hola
    }
};

auto winSize = CCDirector::get()->getWinSize();

//
auto logoStereo = CCSprite::create("logoStereoDash.png");

if (logoStereo) {
    logoStereo->setID("stereo-logo-final");
    logoStereo->setScale(0.4f);
    
    //
    //
    logoStereo->setPosition({ winSize.width * 0.5f, winSize.height * 0.75f });
    logoStereo->setZOrder(100);
    
    this->addChild(logoStereo);
} else {
    //
    log::error("No se encontro la imagen del logo en los recursos");
}