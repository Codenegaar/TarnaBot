QT       += core network
QT       -= gui

TARGET = tarnabot
TEMPLATE = lib
DEFINES += TARNABOT_LIBRARY
VERSION = 1.0

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
    src/inputmessagecontent.cpp \
    src/inputtextmessagecontent.cpp \
    src/inputlocationmessagecontent.cpp \
    src/inputvenuemessagecontent.cpp \
    src/inputcontactmessagecontent.cpp \
    src/inlinequeryresult.cpp \
    src/inputmedia.cpp \
    src/inputmediaphoto.cpp \
    src/inputmediavideo.cpp \
    src/inlinequeryresultarticle.cpp \
    src/inlinequeryresultphoto.cpp \
    src/inlinequeryresultgif.cpp \
    src/inlinequeryresultmpeg4gif.cpp \
    src/inlinequeryresultvideo.cpp \
    src/inlinequeryresultaudio.cpp \
    src/inlinequeryresultvoice.cpp \
    src/inlinequeryresultdocument.cpp \
    src/inlinequeryresultlocation.cpp \
    src/inlinequeryresultvenue.cpp \
    src/inlinequeryresultcontact.cpp \
    src/inlinequeryresultgame.cpp \
    src/inlinequeryresultcachedphoto.cpp \
    src/inlinequeryresultcachedgif.cpp \
    src/inlinequeryresultcachedmpeg4gif.cpp \
    src/inlinequeryresultcachedsticker.cpp \
    src/inlinequeryresultcacheddocument.cpp \
    src/inlinequeryresultcachedvideo.cpp \
    src/inlinequeryresultcachedvoice.cpp \
    src/inlinequeryresultcachedaudio.cpp \
    src/replymarkup.cpp \
    src/tarnabot.cpp \
    src/telegramobject.cpp \
    src/passportfile.cpp \
    src/encryptedpassportelement.cpp \
    src/encryptedcredentials.cpp \
    src/passportelementerror.cpp \
    src/passportelementerrordatafield.cpp \
    src/passportelementerrorfronside.cpp \
    src/passportelementerrorreverseside.cpp \
    src/passportelementerrorselfie.cpp \
    src/passportelementerrorfile.cpp \
    src/passportelementerrorfiles.cpp \
    src/passportelementerrortranslationfile.cpp \
    src/passportelementerrortranslationfiles.cpp \
    src/passportelementerrorunspecified.cpp \
    src/tarnasender.cpp \
    src/tarnabasicsender.cpp

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
    include/inputmessagecontent.h \
    include/inputtextmessagecontent.h \
    include/inputlocationmessagecontent.h \
    include/inputvenuemessagecontent.h \
    include/inputcontactmessagecontent.h \
    include/inlinequeryresult.h \
    include/inputmedia.h \
    include/inputmediaphoto.h \
    include/inputmediavideo.h \
    include/inlinequeryresultarticle.h \
    include/inlinequeryresultphoto.h \
    include/inlinequeryresultgif.h \
    include/inlinequeryresultmpeg4gif.h \
    include/inlinequeryresultvideo.h \
    include/inlinequeryresultaudio.h \
    include/inlinequeryresultvoice.h \
    include/inlinequeryresultdocument.h \
    include/inlinequeryresultlocation.h \
    include/inlinequeryresultvenue.h \
    include/inlinequeryresultcontact.h \
    include/inlinequeryresultgame.h \
    include/inlinequeryresultcachedphoto.h \
    include/inlinequeryresultcachedgif.h \
    include/inlinequeryresultcachedmpeg4gif.h \
    include/inlinequeryresultcachedsticker.h \
    include/inlinequeryresultcacheddocument.h \
    include/inlinequeryresultcachedvideo.h \
    include/inlinequeryresultcachedvoice.h \
    include/inlinequeryresultcachedaudio.h \
    include/replymarkup.h \
    include/tarnabot.h \
    include/telegramobject.h \
    include/tarnabot_global.h \
    include/passportfile.h \
    include/encryptedpassportelement.h \
    include/encryptedcredentials.h \
    include/passportelementerror.h \
    include/passporttype.h \
    include/passportelementerrordatafield.h \
    include/passportelementerrorfronside.h \
    include/passportelementerrorreverseside.h \
    include/passportelementerrorselfie.h \
    include/passportelementerrorfile.h \
    include/passportelementerrorfiles.h \
    include/passportelementerrortranslationfile.h \
    include/passportelementerrortranslationfiles.h \
    include/passportelementerrorunspecified.h \
    include/tarnasender.h \
    include/tarnabasicsender.h
unix {
    target.path = /usr/lib
    header_files.path = /usr/include/TarnaBot
    header_files.files = include/*
    INSTALLS += target
    INSTALLS += header_files
}
