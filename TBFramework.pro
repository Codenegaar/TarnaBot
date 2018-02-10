QT       += core network

QT       -= gui

TARGET = TBFramework
TEMPLATE = lib

SOURCES += src/update.cpp \
    src/user.cpp \
    src/message.cpp \
    src/chat.cpp \
    src/messageentity.cpp \
    src/photosize.cpp \
    src/audio.cpp \
    src/document.cpp \
    src/video.cpp \
    src/voice.cpp \
    src/videonote.cpp \
    src/contact.cpp \
    src/location.cpp \
    src/venue.cpp \
    src/userprofilephotos.cpp \
    src/file.cpp \
    src/replykeyboardmarkup.cpp \
    src/keyboardbutton.cpp \
    src/replykeyboardremove.cpp \
    src/inlinekeyboardmarkup.cpp \
    src/inlinekeyboardbutton.cpp \
    src/callbackquery.cpp \
    src/forcereply.cpp \
    src/chatphoto.cpp \
    src/chatmember.cpp \
    src/responseparameters.cpp \
    src/sticker.cpp \
    src/stickerset.cpp \
    src/maskposition.cpp \
    src/inlinequery.cpp \
    src/inlinequeryresult.cpp \
    src/inlinequeryresultarticle.cpp \
    src/choseninlineresult.cpp \
    src/labeledprice.cpp \
    src/invoice.cpp \
    src/shippingaddress.cpp \
    src/orderinfo.cpp \
    src/shippingoption.cpp \
    src/successfulpayment.cpp \
    src/shippingquery.cpp \
    src/precheckoutquery.cpp \
    src/game.cpp \
    src/animation.cpp \
    src/gamehighscore.cpp \
    src/callbackgame.cpp \
    src/tarnaobject.cpp \
    src/tarnabot.cpp \
    src/inputmedia.cpp \
    src/inputmediaphoto.cpp \
    src/inputmessagecontent.cpp \
    src/inputtextmessagecontent.cpp \
    src/inputlocationmessagecontent.cpp \
    src/inputvenuemessagecontent.cpp \
    src/inputcontactmessagecontent.cpp

HEADERS += include/update.h \
    include/user.h \
    include/message.h \
    include/chat.h \
    include/messageentity.h \
    include/photosize.h \
    include/audio.h \
    include/document.h \
    include/video.h \
    include/voice.h \
    include/videonote.h \
    include/contact.h \
    include/location.h \
    include/venue.h \
    include/userprofilephotos.h \
    include/file.h \
    include/replykeyboardmarkup.h \
    include/keyboardbutton.h \
    include/replykeyboardremove.h \
    include/inlinekeyboardmarkup.h \
    include/inlinekeyboardbutton.h \
    include/callbackquery.h \
    include/forcereply.h \
    include/chatphoto.h \
    include/chatmember.h \
    include/responseparameters.h \
    include/sticker.h \
    include/stickerset.h \
    include/maskposition.h \
    include/inlinequery.h \
    include/inlinequeryresult.h \
    include/inlinequeryresultarticle.h \
    include/choseninlineresult.h \
    include/labeledprice.h \
    include/invoice.h \
    include/shippingaddress.h \
    include/orderinfo.h \
    include/shippingoption.h \
    include/successfulpayment.h \
    include/shippingquery.h \
    include/precheckoutquery.h \
    include/game.h \
    include/animation.h \
    include/gamehighscore.h \
    include/callbackgame.h \
    include/tarnaobject.h \
    include/tarnabot.h \
    include/inputmedia.h \
    include/inputmediaphoto.h \
    include/inputmessagecontent.h \
    include/inputtextmessagecontent.h \
    include/inputlocationmessagecontent.h \
    include/inputvenuemessagecontent.h \
    include/inputcontactmessagecontent.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

STATECHARTS +=
