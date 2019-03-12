#ifndef PASSPORTTYPES_H
#define PASSPORTTYPES_H

#include <QHash>
#include <QByteArray>

namespace Telegram
{
    enum PassportType {
        PersonalDetails,
        Passport,
        DriverLicense,
        IdentityCard,
        InternalPassport,
        Address,
        UtilityBill,
        BankStatement,
        RentalAgreement,
        PassportRegistration,
        TemporaryRegistration,
        PhoneNumber,
        Email
    };

    static bool called = false;
    static QHash< int, QByteArray > typeNames;

    static QHash< int, QByteArray > getTypeNames() {
        if (!called)
        {
            typeNames[PassportType::PersonalDetails] =      "personal_details";
            typeNames[PassportType::Passport] =             "passport";
            typeNames[PassportType::DriverLicense] =        "driver_license";
            typeNames[PassportType::IdentityCard] =         "identity_card";
            typeNames[PassportType::InternalPassport] =     "internal_passport";
            typeNames[PassportType::Address] =              "address";
            typeNames[PassportType::UtilityBill] =          "utility_bill";
            typeNames[PassportType::BankStatement] =        "bank_statement";
            typeNames[PassportType::RentalAgreement] =      "rental_agreement";
            typeNames[PassportType::PassportRegistration] = "passport_registration";
            typeNames[PassportType::TemporaryRegistration] ="temporary_registration";
            typeNames[PassportType::PhoneNumber] =          "phone_number";
            typeNames[PassportType::Email] =                "email";
            called = true;
        }
        return typeNames;
    }
}

#endif // PASSPORTTYPES_H
