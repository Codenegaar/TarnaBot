#ifndef TELEGRAMOBJECT_HPP
#define TELEGRAMOBJECT_HPP

#include <json/json.h>

namespace Tarna
{
//typedef unsigned long long int luint;
//typedef long long int lint;

/*!
 * \brief The TelegramObject class provides an interface for creating
 * bot objects
 */
class TelegramObject
{
public:
    /*!
     * \brief TelegramObject constructor
     * Constructs an empty telegram object
     */
    explicit TelegramObject();
    /*!
     * \brief TelegramObject constructor
     * Constructs a telegram object using the provided JSON object
     * \param jsonDocument The JSON document to build the object with
     */
    explicit TelegramObject(Json::Value jsonObject);

    /*!
     * \brief getRootObject Returns the root JSON object for this object
     * \return A JSON object
     */
    Json::Value getRootObject() const;

protected:
    Json::Value m_rootObject;
};
}
#endif
