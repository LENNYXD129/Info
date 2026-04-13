#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto winSize = CCDirector::get()->getWinSize();

        if (auto bottomMenu = this->getChildByID("bottom-menu")) {
            auto discordSprite = CCSprite::create("DiscordGDPS.png");

            if (!discordSprite) {
                discordSprite = CCSprite::createWithSpriteFrameName("gj_discordIcon_001.png");
            }

            auto discordBtn = CCMenuItemSpriteExtra::create(
                discordSprite,
                this,
                menu_selector(MyMenuLayer::onDiscordClick)
            );

            discordBtn->setID("discord-button-gdps");
            bottomMenu->addChild(discordBtn);
            bottomMenu->updateLayout();
        }

        auto logo = CCSprite::create("logoStereoDash.png");
        if (logo) {
            logo->setID("stereo-logo");
            
            //
            logo->setScale(0.85f); 
            
            //
            if (auto mainTitle = this->getChildByID("main-title")) {
                // Obtenemos su posición y tamaño
                auto titlePos = mainTitle->getPosition();
                auto titleSize = mainTitle->getContentSize();
                
                //
                //
                logo->setAnchorPoint({0.0f, 0.0f}); 
                
                //
                //
                
                //
                float posX = titlePos.x - (titleSize.width / 2.0f); 
                
                //
                //
                float posY = titlePos.y - (titleSize.height / 2.0f) - 10.0f; 
                
                logo->setPosition({ posX, posY });
                
            } else {
                //
                //
                logo->setAnchorPoint({0.0f, 0.0f});
                logo->setPosition({ winSize.width * 0.05f, winSize.height * 0.9f });
            }
            
            //
            this->addChild(logo, 150);
        }

        return true;
    }

    void onDiscordClick(CCObject* sender) {
        utils::web::openLinkInBrowser("https://discord.gg/bzS2cmCGt4");
    }
};