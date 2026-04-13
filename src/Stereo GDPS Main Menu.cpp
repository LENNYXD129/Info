#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

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

        return true;
    }

    void onDiscordClick(CCObject* sender) {
        utils::web::openLinkInBrowser("https://discord.gg/bzS2cmCGt4");
    }
};