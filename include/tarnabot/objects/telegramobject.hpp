#ifndef TELEGRAMOBJECT_HPP
#define TELEGRAMOBJECT_HPP

#include <json-c/json_object.h>

using rapidjson::Document;

namespace Tarna
{
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
     * Constructs a telegram object using the provided JSON document
     * \param jsonDocument The JSON document to build the object with
     */
    explicit TelegramObject(int i);

    /*!
     * \brief toJsonDocument returns the JSON document held by this object
     * Used for sending requests
     * \return the JSON document
     */

protected:
};
}
#endif
