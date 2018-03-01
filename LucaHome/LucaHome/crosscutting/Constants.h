/***********************************************/
/*************** USER DEFINITIONS **************/
/***********************************************/

#define DEFAULT_PASSWORD "0000"
#define MAX_INVALID_LOGIN_COUNT 5
#define NO_PASSWORD "NO_PASSWORD"
#define DUMMY "DUMMY"
#define TASKER "Tasker"
#define TASKER_PASSWORD "435435"

#define RECEIVER_MAIL "TODO_PUT_HERE_YOUR_RECEIVER_MAIL"

/***********************************************/
/************* SUCCESS DEFINITIONS *************/
/***********************************************/

#define AUTHENTIFICATION_RESET_FAILED_LOGIN_COUNT_SUCCESS "AUTHENTIFICATION:RESET_FAILED_LOGIN_COUNT:SUCCESS"

#define APPLICATION_INFORMATION_ADD_SUCCESS "APPLICATION_INFORMATION:ADD:SUCCESS"
#define APPLICATION_INFORMATION_UPDATE_SUCCESS "APPLICATION_INFORMATION:UPDATE:SUCCESS"
#define APPLICATION_INFORMATION_DELETE_SUCCESS "APPLICATION_INFORMATION:DELETE:SUCCESS"

#define CHANGE_ADD_SUCCESS "CHANGE:ADD:SUCCESS"
#define CHANGE_UPDATE_SUCCESS "CHANGE:UPDATE:SUCCESS"
#define CHANGE_DELETE_SUCCESS "CHANGE:DELETE:SUCCESS"

#define COIN_ADD_SUCCESS "COIN:ADD:SUCCESS"
#define COIN_UPDATE_SUCCESS "COIN:UPDATE:SUCCESS"
#define COIN_DELETE_SUCCESS "COIN:DELETE:SUCCESS"

#define CONTACT_ADD_SUCCESS "CONTACT:ADD:SUCCESS"
#define CONTACT_UPDATE_SUCCESS "CONTACT:UPDATE:SUCCESS"
#define CONTACT_DELETE_SUCCESS "CONTACT:DELETE:SUCCESS"
#define CONTACT_MAIL_SUCCESS "CONTACT:MAIL:SUCCESS"

#define COMMAND_RELOAD_SUCCESS "COMMAND:RELOAD:SUCCESS"

#define GPIO_ADD_SUCCESS "GPIO:ADD:SUCCESS"
#define GPIO_UPDATE_SUCCESS "GPIO:UPDATE:SUCCESS"
#define GPIO_DELETE_SUCCESS "GPIO:DELETE:SUCCESS"
#define GPIO_SET_SUCCESS "GPIO:SET:SUCCESS"

#define MAP_CONTENT_ADD_SUCCESS "MAP_CONTENT:ADD:SUCCESS"
#define MAP_CONTENT_UPDATE_SUCCESS "MAP_CONTENT:UPDATE:SUCCESS"
#define MAP_CONTENT_DELETE_SUCCESS "MAP_CONTENT:DELETE:SUCCESS"

#define MEAL_ADD_SUCCESS "MEAL:ADD:SUCCESS"
#define MEAL_UPDATE_SUCCESS "MEAL:UPDATE:SUCCESS"
#define MEAL_DELETE_SUCCESS "MEAL:DELETE:SUCCESS"

#define MEDIA_SERVER_ADD_SUCCESS "MEDIA_SERVER:ADD:SUCCESS"
#define MEDIA_SERVER_UPDATE_SUCCESS "MEDIA_SERVER:UPDATE:SUCCESS"
#define MEDIA_SERVER_DELETE_SUCCESS "MEDIA_SERVER:DELETE:SUCCESS"

#define METER_LOG_ITEM_ADD_SUCCESS "METER_LOG_ITEM:ADD:SUCCESS"
#define METER_LOG_ITEM_UPDATE_SUCCESS "METER_LOG_ITEM:UPDATE:SUCCESS"
#define METER_LOG_ITEM_DELETE_SUCCESS "METER_LOG_ITEM:DELETE:SUCCESS"

#define MONEY_LOG_ITEM_ADD_SUCCESS "MONEY_LOG_ITEM:ADD:SUCCESS"
#define MONEY_LOG_ITEM_UPDATE_SUCCESS "MONEY_LOG_ITEM:UPDATE:SUCCESS"
#define MONEY_LOG_ITEM_DELETE_SUCCESS "MONEY_LOG_ITEM:DELETE:SUCCESS"

#define MOVIE_UPDATE_SUCCESS "MOVIE:UPDATE:SUCCESS"
#define MOVIE_LOAD_SUCCESS "MOVIE:LOAD:SUCCESS"

#define PUCK_JS_ADD_SUCCESS "PUCKJS:ADD:SUCCESS"
#define PUCK_JS_UPDATE_SUCCESS "PUCKJS:UPDATE:SUCCESS"
#define PUCK_JS_DELETE_SUCCESS "PUCKJS:DELETE:SUCCESS"

#define RADIO_STREAM_ADD_SUCCESS "RADIO_STREAM:ADD:SUCCESS"
#define RADIO_STREAM_UPDATE_SUCCESS "RADIO_STREAM:UPDATE:SUCCESS"
#define RADIO_STREAM_DELETE_SUCCESS "RADIO_STREAM:DELETE:SUCCESS"

#define ROOM_ADD_SUCCESS "ROOM:ADD:SUCCESS"
#define ROOM_UPDATE_SUCCESS "ROOM:UPDATE:SUCCESS"
#define ROOM_DELETE_SUCCESS "ROOM:DELETE:SUCCESS"

#define RSS_FEED_ADD_SUCCESS "RSS_FEED:ADD:SUCCESS"
#define RSS_FEED_UPDATE_SUCCESS "RSS_FEED:UPDATE:SUCCESS"
#define RSS_FEED_DELETE_SUCCESS "RSS_FEED:DELETE:SUCCESS"

#define SECURITY_START_MOTION_SUCCESS "SECURITY:START_MOTION:SUCCESS"
#define SECURITY_STOP_MOTION_SUCCESS "SECURITY:STOP_MOTION:SUCCESS"

#define SHOPPING_ITEM_ADD_SUCCESS "SHOPPING_ITEM:ADD:SUCCESS"
#define SHOPPING_ITEM_UPDATE_SUCCESS "SHOPPING_ITEM:UPDATE:SUCCESS"
#define SHOPPING_ITEM_DELETE_SUCCESS "SHOPPING_ITEM:DELETE:SUCCESS"

#define SUGGESTED_MEAL_ADD_SUCCESS "SUGGESTED_MEAL:ADD:SUCCESS"
#define SUGGESTED_MEAL_UPDATE_SUCCESS "SUGGESTED_MEAL:UPDATE:SUCCESS"
#define SUGGESTED_MEAL_DELETE_SUCCESS "SUGGESTED_MEAL:DELETE:SUCCESS"

#define SUGGESTED_SHOPPING_ITEM_ADD_SUCCESS "SUGGESTED_SHOPPING_ITEM:ADD:SUCCESS"
#define SUGGESTED_SHOPPING_ITEM_UPDATE_SUCCESS "SUGGESTED_SHOPPING_ITEM:UPDATE:SUCCESS"
#define SUGGESTED_SHOPPING_ITEM_DELETE_SUCCESS "SUGGESTED_SHOPPING_ITEM:DELETE:SUCCESS"

#define USER_VALIDATE_SUCCESS "USER:VALIDATE:SUCCESS"
#define USER_ADD_SUCCESS "USER:ADD:SUCCESS"
#define USER_UPDATE_SUCCESS "USER:UPDATE:SUCCESS"
#define USER_DELETE_SUCCESS "USER:DELETE:SUCCESS"

#define WIRELESS_SCHEDULE_ADD_SUCCESS "WIRELESS_SCHEDULE:ADD:SUCCESS"
#define WIRELESS_SCHEDULE_UPDATE_SUCCESS "WIRELESS_SCHEDULE:UPDATE:SUCCESS"
#define WIRELESS_SCHEDULE_DELETE_SUCCESS "WIRELESS_SCHEDULE:DELETE:SUCCESS"
#define WIRELESS_SCHEDULE_SET_SUCCESS "WIRELESS_SCHEDULE:SET:SUCCESS"

#define WIRELESS_SOCKET_ADD_SUCCESS "WIRELESS_SOCKET:ADD:SUCCESS"
#define WIRELESS_SOCKET_UPDATE_SUCCESS "WIRELESS_SOCKET:UPDATE:SUCCESS"
#define WIRELESS_SOCKET_DELETE_SUCCESS "WIRELESS_SOCKET:DELETE:SUCCESS"
#define WIRELESS_SOCKET_SET_SUCCESS "WIRELESS_SOCKET:SET:SUCCESS"

#define WIRELESS_SWITCH_ADD_SUCCESS "WIRELESS_SWITCH:ADD:SUCCESS"
#define WIRELESS_SWITCH_UPDATE_SUCCESS "WIRELESS_SWITCH:UPDATE:SUCCESS"
#define WIRELESS_SWITCH_DELETE_SUCCESS "WIRELESS_SWITCH:DELETE:SUCCESS"
#define WIRELESS_SWITCH_TOGGLE_SUCCESS "WIRELESS_SOCKET:TOGGLE:SUCCESS"

#define WIRELESS_TIMER_ADD_SUCCESS "WIRELESS_TIMER:ADD:SUCCESS"
#define WIRELESS_TIMER_UPDATE_SUCCESS "WIRELESS_TIMER:UPDATE:SUCCESS"
#define WIRELESS_TIMER_DELETE_SUCCESS "WIRELESS_TIMER:DELETE:SUCCESS"
#define WIRELESS_TIMER_SET_SUCCESS "WIRELESS_TIMER:SET:SUCCESS"

#define YOUTUBE_VIDEO_ADD_SUCCESS "YOUTUBE_VIDEO:ADD:SUCCESS"
#define YOUTUBE_VIDEO_UPDATE_SUCCESS "YOUTUBE_VIDEO:UPDATE:SUCCESS"
#define YOUTUBE_VIDEO_DELETE_SUCCESS "YOUTUBE_VIDEO:DELETE:SUCCESS"

/***********************************************/
/************** ERROR DEFINITIONS **************/
/***********************************************/

#define AUTHENTIFICATION_ERROR_FAILED "Error 10:Authentification failed"
#define AUTHENTIFICATION_ERROR_NO_RIGHTS "Error 11:UserAction cannot be performed! No rights"
#define AUTHENTIFICATION_ERROR_NO_PASSWORD "Error 12:No password"
#define AUTHENTIFICATION_ERROR_NO_USERNAME "Error 13:No username"
#define AUTHENTIFICATION_ERROR_INVALID_SOURCE "Error 14:Invalid source"
#define AUTHENTIFICATION_ERROR_RESET_FAILED "Error 16:Could not reset invalid login count"
#define AUTHENTIFICATION_ERROR_NO_ADMIN "Error 17:Permitted! User is no admin!"
#define AUTHENTIFICATION_ERROR_NO_HANDSHAKE "Error 18:No handshake performed!"

#define COMMAND_ERROR_NO_ACTION_FOUND "Error 20:action not found"
#define COMMAND_ERROR_NO_PARAMETER_FOUND "Error 21:parameter not found"
#define COMMAND_ERROR_SHORT_STATEMENT "Error 22:statement too short"
#define COMMAND_ERROR_NO_ACTION "Error 23:No action"
#define COMMAND_ERROR_NO_CATEGORY "Error 24:No category"
#define COMMAND_ERROR_NO_PARAMETER "Error 25:No action parameter"
#define COMMAND_ERROR_SCHEDULER_EXTERNAL_NOT_ALLOWED "Error 26:tasker not allowed from external source"
#define COMMAND_ERROR_HANDLER_NOT_INITIALIZED "Error 27:Handler is not initialized! Restart server!"
#define COMMAND_ERROR_PIPE_ERROR "Error 28:System command error. Pipe Error!"

#define APPLICATION_INFORMATION_ERROR_ADD "Error 261:Could not add application information"
#define APPLICATION_INFORMATION_ERROR_UPDATE "Error 262:Could not update application information"
#define APPLICATION_INFORMATION_ERROR_DELETE "Error 263:Could not delete application information"
#define APPLICATION_INFORMATION_ERROR_WRONG_WORD_SIZE "Error 264:Wrong word size for application information"

#define CHANGE_ERROR_ADD "Error 271:Could not add change"
#define CHANGE_ERROR_UPDATE "Error 272:Could not update change"
#define CHANGE_ERROR_DELETE "Error 273:Could not delete change"
#define CHANGE_ERROR_WRONG_WORD_SIZE "Error 274:Wrong word size for change"

#define COIN_ERROR_ADD "Error 171:Could not add coin"
#define COIN_ERROR_UPDATE "Error 172:Could not update coin"
#define COIN_ERROR_DELETE "Error 173:Could not delete coin"
#define COIN_ERROR_WRONG_WORD_SIZE "Error 174:Wrong word size for coin"

#define CONTACT_ERROR_ADD "Error 31:Failed to add contact"
#define CONTACT_ERROR_UPDATE "Error 32:Failed to update contact"
#define CONTACT_ERROR_DELETE "Error 33:Failed to delete contact"
#define CONTACT_ERROR_WRONG_WORD_SIZE "Error 34:Wrong word size for contact"
#define CONTACT_ERROR_INVALID_DATA "Error 39:Invalid data for contact"

#define DECRYPT_ERROR_KEY_NULL "Error 300:Failed to decrypt! key is null"
#define ENCRYPT_ERROR_KEY_NULL "Error 301:Failed to encrypt! key is null"

#define GPIO_ERROR_SET "Error 290:Could not set gpio"
#define GPIO_ERROR_ADD "Error 291:Could not add gpio"
#define GPIO_ERROR_UPDATE "Error 292:Could not update gpio"
#define GPIO_ERROR_DELETE "Error 293:Could not delete gpio"
#define GPIO_ERROR_WRONG_WORD_SIZE "Error 294:Wrong word size for gpio"
#define GPIO_ERROR_INVALID_STATE "Error 299:Invalid state for gpio"

#define MAP_CONTENT_ERROR_ADD "Error 101:Could not add mapcontent"
#define MAP_CONTENT_ERROR_UPDATE "Error 102:Could not update mapcontent"
#define MAP_CONTENT_ERROR_DELETE "Error 103:Could not delete mapcontent"
#define MAP_CONTENT_ERROR_WRONG_WORD_SIZE "Error 104:Wrong word size for mapcontent"

#define MEAL_ERROR_ADD "Error 131:Could not add meal"
#define MEAL_ERROR_UPDATE "Error 132:Could not update meal"
#define MEAL_ERROR_DELETE "Error 133:Could not delete meal"
#define MEAL_ERROR_WRONG_WORD_SIZE "Error 134:Wrong word size for meal"
#define MEAL_ERROR_INVALID_DATA "Error 139:Invalid data for meal"

#define MEDIA_SERVER_ERROR_ADD "Error 211:Could not add mediaserver"
#define MEDIA_SERVER_ERROR_UPDATE "Error 212:Could not update mediaserver"
#define MEDIA_SERVER_ERROR_DELETE "Error 213:Could not delete mediaserver"
#define MEDIA_SERVER_ERROR_WRONG_SIZE "Error 214:Wrong word size for mediaserver"

#define METER_LOG_ITEM_ERROR_ADD "Error 161:Could not add meter log item"
#define METER_LOG_ITEM_ERROR_UPDATE "Error 162:Could not update meter log item"
#define METER_LOG_ITEM_ERROR_DELETE "Error 163:Could not delete meter log item"
#define METER_LOG_ITEM_ERROR_WRONG_WORD_SIZE "Error 164:Wrong word size for meter log item"
#define METER_LOG_ITEM_ERROR_INVALID_DATA "Error 169:Invalid data for meter log item"

#define MONEY_LOG_ITEM_ERROR_ADD "Error 181:Could not add money log item"
#define MONEY_LOG_ITEM_ERROR_UPDATE "Error 182:Could not update money log item"
#define MONEY_LOG_ITEM_ERROR_DELETE "Error 183:Could not delete money log item"
#define MONEY_LOG_ITEM_ERROR_WRONG_WORD_SIZE "Error 184:Wrong word size for money log item"
#define MONEY_LOG_ITEM_ERROR_INVALID_DATA "Error 189:Invalid data for money log item"

#define MOVIE_ERROR_UPDATE "Error 42:Could not update movie"
#define MOVIE_ERROR_WRONG_WORD_SIZE "Error 44:Wrong word size for movie"
#define MOVIE_ERROR_INVALID_INDEX "Error 49:Start index higher then last index value"

#define PUCK_JS_ERROR_ADD "Error 191:Could not add puckjs"
#define PUCK_JS_ERROR_UPDATE "Error 192:Could not update puckjs"
#define PUCK_JS_ERROR_DELETE "Error 193:Could not delete puckjs"
#define PUCK_JS_ERROR_WRONG_WORD_SIZE "Error 194:Wrong word size for puckjs"

#define RADIO_STREAM_ERROR_ADD "Error 231:Could not add radio stream"
#define RADIO_STREAM_ERROR_UPDATE "Error 232:Could not update radio stream"
#define RADIO_STREAM_ERROR_DELETE "Error 233:Could not delete radio stream"
#define RADIO_STREAM_ERROR_WRONG_WORD_SIZE "Error 234:Wrong word size for radio stream"

#define ROOM_ERROR_ADD "Error 201:Could not add room"
#define ROOM_ERROR_UPDATE "Error 202:Could not update room"
#define ROOM_ERROR_DELETE "Error 203:Could not delete room"
#define ROOM_ERROR_WRONG_WORD_SIZE "Error 204:Wrong word size for room"

#define RSS_FEED_ERROR_ADD "Error 241:Could not add rss feed"
#define RSS_FEED_ERROR_UPDATE "Error 242:Could not update rss feed"
#define RSS_FEED_ERROR_DELETE "Error 243:Could not delete rss feed"
#define RSS_FEED_ERROR_WRONG_WORD_SIZE "Error 244:Wrong word size for rss feed"

#define SECURITY_ERROR_MOTION_IS_RUNNING "Error 156:Security motion already running"
#define SECURITY_ERROR_MOTION_NOT_RUNNING "Error 157:Security motion not running"
#define SECURITY_ERROR_INVALID_INDEX_5_DATA "Error 158:Invalid data at index 5 for security"
#define SECURITY_ERROR_INVALID_DATA "Error 159:Invalid data for security"

#define SHOPPING_ITEM_ERROR_ADD "Error 111:Could not add shopping item"
#define SHOPPING_ITEM_ERROR_UPDATE "Error 112:Could not update shopping item"
#define SHOPPING_ITEM_ERROR_DELETE "Error 113:Could not delete shopping item"
#define SHOPPING_ITEM_ERROR_WRONG_WORD_SIZE "Error 114:Wrong word size for shopping item"

#define SUGGESTED_MEAL_ERROR_ADD "Error 141:Could not add suggested meal"
#define SUGGESTED_MEAL_ERROR_UPDATE "Error 142:Could not update suggested meal"
#define SUGGESTED_MEAL_ERROR_DELETE "Error 143:Could not delete suggested meal"
#define SUGGESTED_MEAL_ERROR_WRONG_WORD_SIZE "Error 144:Wrong word size for suggested meal"

#define SUGGESTED_SHOPPING_ITEM_ERROR_ADD "Error 121:Could not add suggested shopping item"
#define SUGGESTED_SHOPPING_ITEM_ERROR_UPDATE "Error 122:Could not update suggested shopping item"
#define SUGGESTED_SHOPPING_ITEM_ERROR_DELETE "Error 123:Could not delete suggested shopping item"
#define SUGGESTED_SHOPPING_ITEM_ERROR_WRONG_WORD_SIZE "Error 124:Wrong word size for suggested shopping item"

#define TEMPERATURE_ERROR_NOT_INITIALIZED "Error 98:Temperature is not initialized"
#define TEMPERATURE_ERROR_INVALID_DATA "Error 99:Invalid data for temperature"

#define USER_ERROR_ADD "Error 251:Could not add user"
#define USER_ERROR_UPDATE "Error 252:Could not update user"
#define USER_ERROR_DELETE "Error 253:Could not delete user"
#define USER_ERROR_WRONG_WORD_SIZE "Error 254:Wrong word size for user"

#define WIRELESS_SCHEDULE_ERROR_SET "Error 60:Could not set wireless schedule"
#define WIRELESS_SCHEDULE_ERROR_ADD "Error 61:Could not add wireless schedule"
#define WIRELESS_SCHEDULE_ERROR_UPDATE "Error 62:Could not update wireless schedule"
#define WIRELESS_SCHEDULE_ERROR_DELETE "Error 63:Could not delete wireless schedule"
#define WIRELESS_SCHEDULE_ERROR_WRONG_WORD_SIZE "Error 64:Wrong word size for wireless schedule"
#define WIRELESS_SCHEDULE_ERROR_INVALID_STATE "Error 69:Invalid state for wireless schedule"

#define WIRELESS_SOCKET_ERROR_SET "Error 70:Could not set wireless socket"
#define WIRELESS_SOCKET_ERROR_ADD "Error 71:Could not add wireless socket"
#define WIRELESS_SOCKET_ERROR_UPDATE "Error 72:Could not update wireless socket"
#define WIRELESS_SOCKET_ERROR_DELETE "Error 73:Could not delete wireless socket"
#define WIRELESS_SOCKET_ERROR_WRONG_WORD_SIZE "Error 74:Wrong word size for wireless socket"
#define WIRELESS_SOCKET_ERROR_INVALID_STATE "Error 79:Invalid state for wireless socket"

#define WIRELESS_SWITCH_ERROR_TOGGLE "Error 80:Could not toggle wireless switch"
#define WIRELESS_SWITCH_ERROR_ADD "Error 81:Could not add wireless switch"
#define WIRELESS_SWITCH_ERROR_UPDATE "Error 82:Could not update wireless switch"
#define WIRELESS_SWITCH_ERROR_DELETE "Error 83:Could not delete wireless switch"
#define WIRELESS_SWITCH_ERROR_WRONG_WORD_SIZE "Error 84:Wrong word size for wireless switch"

#define WIRELESS_TIMER_ERROR_SET "Error 280:Could not set wireless timer"
#define WIRELESS_TIMER_ERROR_ADD "Error 281:Could not add wireless timer"
#define WIRELESS_TIMER_ERROR_UPDATE "Error 282:Could not update wireless timer"
#define WIRELESS_TIMER_ERROR_DELETE "Error 283:Could not delete wireless timer"
#define WIRELESS_TIMER_ERROR_WRONG_WORD_SIZE "Error 284:Wrong word size for wireless timer"
#define WIRELESS_TIMER_ERROR_INVALID_STATE "Error 289:Invalid state for wireless timer"

#define YOUTUBE_VIDEO_ERROR_ADD "Error 221:Could not add youtube video"
#define YOUTUBE_VIDEO_ERROR_UPDATE "Error 222:Could not update youtube video"
#define YOUTUBE_VIDEO_ERROR_DELETE "Error 223:Could not delete youtube video"
#define YOUTUBE_VIDEO_ERROR_WRONG_WORD_SIZE "Error 224:Wrong word size for youtube video"

/***********************************************/
/************* COMMAND DEFINITIONS *************/
/***********************************************/

#define COMMAND_SPLITTER "::"

#define ACTIVATE "ACTIVATE"
#define DEACTIVATE "DEACTIVATE"
#define TOGGLE "TOGGLE"

#define SET "SET"
#define ADD "ADD"
#define CLEAR "CLEAR"
#define DELETE "DELETE"
#define UPDATE "UPDATE"
#define MAIL "MAIL"

#define ON "ON"
#define OFF "OFF"
#define ACTIVE "ACTIVE"
#define INACTIVE "INACTIVE"

#define ALL "ALL"
#define FOR_USER "FOR_USER"

#define AVAILABILITY "AVAILABILITY"
#define CHECK "CHECK"
#define CONTROL "CONTROL"
#define COUNT "COUNT"
#define DATA "DATA"
#define GET "GET"
#define INDEX "INDEX"
#define LOAD "LOAD"
#define MAIN "MAIN"
#define MOTION "MOTION"
#define PHP "PHP"
#define PLAY "PLAY"
#define RESETFAILEDLOGIN "RESETFAILEDLOGIN"
#define SENSOR "SENSOR"
#define START "START"
#define STATE "STATE"
#define STOP "STOP"
#define URL "URL"
#define VALIDATE "VALIDATE"

#define MOTION_EVENTS_MAX_COUNT 100
#define MOTION_IMAGES_TO_SEND 10

#define MAIL_MIN_ADDRESS_LENGTH 9
#define MAIL_MAX_DATA_LENGTH 4096

#define APPLICATIONINFORMATION "APPLICATIONINFORMATION"
#define CHANGE "CHANGE"
#define COIN "COIN"
#define CONTACT "CONTACT"
#define GPIO "GPIO"
#define MAPCONTENT "MAPCONTENT"
#define MEAL "MEAL"
#define MEDIASERVER "MEDIASERVER"
#define METERLOGITEM "METERLOGITEM"
#define MONEYLOGITEM "MONEYLOGITEM"
#define MOVIE "MOVIE"
#define PUCKJS "PUCKJS"
#define RADIOSTREAM "RADIOSTREAM"
#define ROOM "ROOM"
#define RSSFEED "RSSFEED"
#define SECURITY "SECURITY"
#define SHOPPINGITEM "SHOPPINGITEM"
#define SUGGESTEDMEAL "SUGGESTEDMEAL"
#define SUGGESTEDSHOPPINGITEM "SUGGESTEDSHOPPINGITEM"
#define TEMPERATURE "TEMPERATURE"
#define USER "USER"
#define WIRELESSSCHEDULE "WIRELESSSCHEDULE"
#define WIRELESSSOCKET "WIRELESSSOCKET"
#define WIRELESSSWITCH "WIRELESSSWITCH"
#define WIRELESSTIMER "WIRELESSTIMER"
#define YOUTUBEVIDEO "YOUTUBEVIDEO"

#define ACTION_LEVEL_ERROR -1
#define ACTION_LEVEL_LOW 1
#define ACTION_LEVEL_MEDIUM 2
#define ACTION_LEVEL_NORMAL 3
#define ACTION_LEVEL_CRIT 4
#define ACTION_LEVEL_SYSTEM 5

#define CMD_MIN_LENGTH 25
#define CMD_MAX_LENGTH 4096
#define CMD_SOURCE_EXTERNAL 1
#define CMD_SOURCE_TASKER 2

#define CMD_SUDO_MOTION "sudo motion"
#define CMD_SUDO_KILLALL_MOTION "sudo killall motion"
#define CMD_SUDO_REBOOT "sudo shutdown -r now"
#define CMD_SUDO_SHUTDOWN "sudo shutdown -h now"

#define CMD_SEND_MAIL "python /etc/default/lucahome/mail.py"

/***********************************************/
/************** INDEX DEFINITIONS **************/
/***********************************************/

#define USER_NAME_INDEX 0
#define PASSWORD_INDEX 1
#define CATEGORY_INDEX 2
#define ACTION_INDEX 3
#define ACTION_PARAMETER_INDEX 4

#define APPLICATION_INFORMATION_KEY_INDEX 4
#define APPLICATION_INFORMATION_VALUE_INDEX 5
#define APPLICATION_INFORMATION_DATA_SIZE 6

#define CAMERA_CMD_PARAMETER_INDEX 5
#define CAMERA_DATA_SIZE 6

#define CHANGE_DATA_SIZE 5

#define COIN_UUID_INDEX 4
#define COIN_USER_UUID_INDEX 5
#define COIN_TYPE_INDEX 6
#define COIN_AMOUNT_INDEX 7
#define COIN_DATA_SIZE 8

#define CONTACT_UUID_INDEX 4
#define CONTACT_NAME_INDEX 5
#define CONTACT_GROUP_INDEX 6
#define CONTACT_ADDRESS_INDEX 7
#define CONTACT_PHONE_HOME_INDEX 8
#define CONTACT_PHONE_MOBILE_INDEX 9
#define CONTACT_EMAIL_INDEX 10
#define CONTACT_BIRTHDAY_DAY_INDEX 11
#define CONTACT_BIRTHDAY_MONTH_INDEX 12
#define CONTACT_BIRTHDAY_YEAR_INDEX 13
#define CONTACT_BIRTHDAY_REMINDME_INDEX 14
#define CONTACT_DATA_SIZE 15
#define CONTACT_MAIL_MESSAGE_INDEX 5
#define CONTACT_MAIL_MESSAGE_DATA_SIZE 15

#define GPIO_UUID_INDEX 4
#define GPIO_NAME_INDEX 5
#define GPIO_PIN_INDEX 6
#define GPIO_STATE_INDEX 7
#define GPIO_DATA_SIZE 8

#define GPIO_SET_STATE_INDEX 5
#define GPIO_SET_DATA_SIZE 6

#define MAP_CONTENT_UUID_INDEX 4
#define MAP_CONTENT_TYPE_UUID_INDEX 5
#define MAP_CONTENT_TYPE_INDEX 6
#define MAP_CONTENT_COORDINATES_X_INDEX 7
#define MAP_CONTENT_COORDINATES_Y_INDEX 8
#define MAP_CONTENT_NAME_INDEX 9
#define MAP_CONTENT_SHORT_NAME_INDEX 10
#define MAP_CONTENT_VISIBILITY_INDEX 11
#define MAP_CONTENT_DATA_SIZE 12

#define MEAL_UUID_INDEX 4
#define MEAL_TITLE_INDEX 5
#define MEAL_DESCRIPTION_INDEX 6
#define MEAL_WEEKDAY_INDEX 7
#define MEAL_DAY_INDEX 8
#define MEAL_MONTH_INDEX 9
#define MEAL_YEAR_INDEX 10
#define MEAL_SHOPPING_UUID_LIST_INDEX 11
#define MEAL_DATA_SIZE 12

#define MEDIA_SERVER_UUID_INDEX 4
#define MEDIA_SERVER_ROOM_UUID_INDEX 5
#define MEDIA_SERVER_IP_INDEX 6
#define MEDIA_SERVER_IS_SLEEPING_SERVER_INDEX 7
#define MEDIA_SERVER_WIRELESS_SOCKET_UUID 8
#define MEDIA_SERVER_DATA_SIZE 9

#define METER_LOG_ITEM_UUID_INDEX 4
#define METER_LOG_ITEM_ROOM_UUID_INDEX 5
#define METER_LOG_ITEM_TYPE_UUID_INDEX 6
#define METER_LOG_ITEM_TYPE_INDEX 7
#define METER_LOG_ITEM_METER_ID_INDEX 8
#define METER_LOG_ITEM_VALUE_INDEX 9
#define METER_LOG_ITEM_IMAGE_NAME_INDEX 10
#define METER_LOG_ITEM_SAVE_DATE_TIME_INDEX 11
#define METER_LOG_ITEM_DATA_SIZE 12

#define MONEY_LOG_ITEM_UUID_INDEX 4
#define MONEY_LOG_ITEM_TYPE_UUID_INDEX 5
#define MONEY_LOG_ITEM_BANK_INDEX 6
#define MONEY_LOG_ITEM_PLAN_INDEX 7
#define MONEY_LOG_ITEM_AMOUNT_INDEX 8
#define MONEY_LOG_ITEM_UNIT_INDEX 9
#define MONEY_LOG_ITEM_USER_UUID_INDEX 10
#define METER_LOG_ITEM_SAVE_DATE_INDEX 11
#define MONEY_LOG_ITEM_DATA_SIZE 12

#define MONEY_LOG_ITEM_GET_USER_UUID_INDEX 5

#define MOVIE_UUID_INDEX 4
#define MOVIE_TITLE_INDEX 5
#define MOVIE_GENRE_INDEX 6
#define MOVIE_DESCRIPTION_INDEX 7
#define MOVIE_RATING_INDEX 8
#define MOVIE_WATCH_COUNT_INDEX 9
#define MOVIE_DATA_SIZE 10

#define MOVIE_LOW_INDEX 5
#define MOVIE_HIGH_INDEX 6
#define MOVIE_ADDITIONAL_INDEX 7
#define MOVIE_INDEX_DATA_SIZE 8

#define PUCK_JS_UUID_INDEX 4
#define PUCK_JS_ROOM_UUID_INDEX 5
#define PUCK_JS_NAME_INDEX 6
#define PUCK_JS_MAC_INDEX 7
#define PUCK_JS_DATA_SIZE 8

#define RADIO_STREAM_UUID_INDEX 4
#define RADIO_STREAM_TITLE_INDEX 5
#define RADIO_STREAM_URL_INDEX 6
#define RADIO_STREAM_PLAY_COUNT_INDEX 7
#define RADIO_STREAM_DATA_SIZE 8

#define ROOM_UUID_INDEX 4
#define ROOM_NAME_INDEX 5
#define ROOM_TYPE_INDEX 6
#define ROOM_POINT_INDEX 7
#define ROOM_DATA_SIZE 8

#define RSS_FEED_UUID_INDEX 4
#define RSS_FEED_TITLE_INDEX 5
#define RSS_FEED_URL_INDEX 6
#define RSS_FEED_PLAY_COUNT_INDEX 7
#define RSS_FEED_DATA_SIZE 8

#define SHOPPING_ITEM_UUID_INDEX 4
#define SHOPPING_ITEM_NAME_INDEX 5
#define SHOPPING_ITEM_TYPE_INDEX 6
#define SHOPPING_ITEM_QUANTITY_INDEX 7
#define SHOPPING_ITEM_UNIT_INDEX 8
#define SHOPPING_ITEM_DATA_SIZE 9

#define SUGGESTED_MEAL_UUID_INDEX 4
#define SUGGESTED_MEAL_TITLE_INDEX 5
#define SUGGESTED_MEAL_DESCRIPTION_INDEX 6
#define SUGGESTED_MEAL_RATING_INDEX 7
#define SUGGESTED_MEAL_USE_COUNTER_INDEX 8
#define SUGGESTED_MEAL_SHOPPING_UUID_LIST_INDEX 9
#define SUGGESTED_MEAL_DATA_SIZE 10

#define SUGGESTED_SHOPPING_ITEM_UUID_INDEX 4
#define SUGGESTED_SHOPPING_ITEM_NAME_INDEX 5
#define SUGGESTED_SHOPPING_ITEM_TYPE_INDEX 6
#define SUGGESTED_SHOPPING_ITEM_QUANTITY_INDEX 7
#define SUGGESTED_SHOPPING_ITEM_UNIT_INDEX 8
#define SUGGESTED_SHOPPING_ITEM_DATA_SIZE 9

#define USER_UUID_INDEX 4
#define USER_DATA_NAME_INDEX 5
#define USER_PASSPHRASE_INDEX 6
#define USER_ROLE_INDEX 7
#define USER_DATA_SIZE 8

#define WIRELESS_SCHEDULE_UUID_INDEX 4
#define WIRELESS_SCHEDULE_NAME_INDEX 5
#define WIRELESS_SCHEDULE_WEEKDAY_INDEX 6
#define WIRELESS_SCHEDULE_HOUR_INDEX 7
#define WIRELESS_SCHEDULE_MINUTE_INDEX 8
#define WIRELESS_SCHEDULE_GPIO_UUID_INDEX 9
#define WIRELESS_SCHEDULE_GPIO_ACTION_INDEX 10
#define WIRELESS_SCHEDULE_WIRELESS_SOCKET_UUID_INDEX 11
#define WIRELESS_SCHEDULE_WIRELESS_SOCKET_ACTION_INDEX 12
#define WIRELESS_SCHEDULE_WIRELESS_SWITCH_UUID_INDEX 13
#define WIRELESS_SCHEDULE_DATA_SIZE 14

#define WIRELESS_SCHEDULE_SET_STATE_INDEX 5
#define WIRELESS_SCHEDULE_SET_DATA_SIZE 6

#define WIRELESS_SOCKET_UUID_INDEX 4
#define WIRELESS_SOCKET_ROOM_UUID_INDEX 5
#define WIRELESS_SOCKET_NAME_INDEX 6
#define WIRELESS_SOCKET_CODE_INDEX 7
#define WIRELESS_SOCKET_DATA_SIZE 8

#define WIRELESS_SOCKET_SET_STATE_INDEX 5
#define WIRELESS_SOCKET_SET_DATA_SIZE 6

#define WIRELESS_SWITCH_UUID_INDEX 4
#define WIRELESS_SWITCH_ROOM_UUID_INDEX 5
#define WIRELESS_SWITCH_NAME_INDEX 6
#define WIRELESS_SWITCH_REMOTE_ID_INDEX 7
#define WIRELESS_SWITCH_KEY_CODE_INDEX 8
#define WIRELESS_SWITCH_ACTION_INDEX 9
#define WIRELESS_SWITCH_DATA_SIZE 10

#define WIRELESS_SWITCH_TOGGLE_DATA_SIZE 5

#define WIRELESS_TIMER_UUID_INDEX 4
#define WIRELESS_TIMER_NAME_INDEX 5
#define WIRELESS_TIMER_WEEKDAY_INDEX 6
#define WIRELESS_TIMER_HOUR_INDEX 7
#define WIRELESS_TIMER_MINUTE_INDEX 8
#define WIRELESS_TIMER_GPIO_UUID_INDEX 9
#define WIRELESS_TIMER_GPIO_ACTION_INDEX 10
#define WIRELESS_TIMER_WIRELESS_SOCKET_UUID_INDEX 11
#define WIRELESS_TIMER_WIRELESS_SOCKET_ACTION_INDEX 12
#define WIRELESS_TIMER_WIRELESS_SWITCH_UUID_INDEX 13
#define WIRELESS_TIMER_DATA_SIZE 14

#define YOUTUBE_VIDEO_UUID_INDEX 4
#define YOUTUBE_VIDEO_TITLE_INDEX 5
#define YOUTUBE_VIDEO_ID_INDEX 6
#define YOUTUBE_VIDEO_PLAY_COUNT_INDEX 7
#define YOUTUBE_VIDEO_DESCRIPTION_INDEX 8
#define YOUTUBE_VIDEO_MEDIUM_IMAGE_URL_INDEX 9
#define YOUTUBE_VIDEO_DATA_SIZE 10

/***********************************************/
/************** TIMEOUT DEFINITIONS ************/
/***********************************************/

#define BIRTHDAY_CHECK_TIMEOUT 2 * 60 * 60
#define MOTION_CONTROL_TIMEOUT 15
#define SHOPPING_ITEM_CHECK_TIMEOUT 2 * 60 * 60
#define TASK_CONTROL_TIMEOUT 10
#define TEMPERATURE_CONTROL_TIMEOUT 60

/***********************************************/
/*************** PATH DEFINITIONS **************/
/***********************************************/

#define NAS_PATH_CAMERA "/mnt/NAS/Camera/"
#define NAS_PATH_LUCAHOME "/mnt/NAS/LucaHome/"
#define NAS_PATH_METER_LOG "/mnt/NAS/MeterLog/"
#define NAS_PATH_MOVIE "/mnt/NAS/Movies/"
#define NAS_PATH_MUSIC "/mnt/NAS/Music/"
#define NAS_PATH_SERIES "/mnt/NAS/Series/"

/***********************************************/
/**************** FILE DEFINITIONS *************/
/***********************************************/

#define IS_FOLDER 0x4
#define IS_FILE 0x8

#define JPG_ENDING ".jpg"
#define SWF_ENDING ".swf"

#define NFO_LUCA_FILE "NFO.luca"

/***********************************************/
/*************** OTHER DEFINITIONS *************/
/***********************************************/

#define DATA_GPIO 17
#define SECONDS_OF_7_DAYS 7 * 24 * 60 * 60

#define BUFFER_LENGTH 512
#define SERVER_PORT 6677
#define TASK_TYPE_SCHEDULE 0
#define TASK_TYPE_TIMER 1
