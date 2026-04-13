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
            logo->setScale(0.4f);
            
            if (auto mainTitle = this->getChildByID("main-title")) {
                auto titlePos = mainTitle->getPosition();
                logo->setPosition({ titlePos.x, titlePos.y - 45.0f });
            } else {
                logo->setPosition({ winSize.width / 2, winSize.height * 0.75f });
            }
            
            this->addChild(logo, 100);
        }

        return true;
    }

    void onDiscordClick(CCObject* sender) {
        utils::web::openLinkInBrowser("https://discord.gg/bzS2cmCGt4");
    }
};