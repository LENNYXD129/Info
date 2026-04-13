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

        auto logo = CCSprite::create("logo Stereo Dash.png");
        if (logo) {
            logo->setID("stereo-logo");
            logo->setScale(0.65f);
            
            if (auto mainTitle = this->getChildByID("main-title")) {
                auto titlePos = mainTitle->getPosition();
                auto titleSize = mainTitle->getContentSize();
                
                //hola
                float posX = titlePos.x - (titleSize.width / 2.0f) + (winSize.width * 0.05f);
                float posY = titlePos.y - (titleSize.height / 2.0f) - 30.0f;
                
                logo->setAnchorPoint({0.0f, 1.0f});
                logo->setPosition({ posX, posY });
            } else {
                logo->setAnchorPoint({0.0f, 1.0f});
                logo->setPosition({ winSize.width * 0.1f, winSize.height * 0.85f });
            }
            
            this->addChild(logo, 150);
        }

        return true;
    }

    void onDiscordClick(CCObject* sender) {
        utils::web::openLinkInBrowser("https://discord.gg/bzS2cmCGt4");
    }
};