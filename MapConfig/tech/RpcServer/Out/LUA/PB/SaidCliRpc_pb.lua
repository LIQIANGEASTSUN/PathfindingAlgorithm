-- Generated By protoc-gen-lua Do not Edit
local protobuf = require "protobuf"
local PublicStruct_pb = require("PublicStruct_pb")
module('SaidCliRpc_pb')


local SAIDRPCSAIDASK = protobuf.Descriptor();
local SAIDRPCSAIDASK_VALUE_FIELD = protobuf.FieldDescriptor();
local SAIDRPCSAIDREPLY = protobuf.Descriptor();
local SAIDRPCSAIDREPLY_RESULT_FIELD = protobuf.FieldDescriptor();
local SAIDRPCSAIDREPLY_VALUE_FIELD = protobuf.FieldDescriptor();
local SAIDRPCSAIDBROADCASNOTIFY = protobuf.Descriptor();
local SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD = protobuf.FieldDescriptor();
local SAIDSAIDDATA = protobuf.Descriptor();
local SAIDSAIDDATA_CHANNEL_FIELD = protobuf.FieldDescriptor();
local SAIDSAIDDATA_CONTENT_FIELD = protobuf.FieldDescriptor();
local SAIDSAIDDATA_WHO_FIELD = protobuf.FieldDescriptor();
local SAIDSAIDDATA_TO_FIELD = protobuf.FieldDescriptor();
local SAIDSAIDDATA_BIGTYPE_FIELD = protobuf.FieldDescriptor();
local SAIDSAIDDATA_SMALLTYPE_FIELD = protobuf.FieldDescriptor();
local SAIDSAIDDATA_ID_FIELD = protobuf.FieldDescriptor();

SAIDRPCSAIDASK_VALUE_FIELD.name = "Value"
SAIDRPCSAIDASK_VALUE_FIELD.full_name = ".SaidRpcSaidAsk.Value"
SAIDRPCSAIDASK_VALUE_FIELD.number = 2
SAIDRPCSAIDASK_VALUE_FIELD.index = 0
SAIDRPCSAIDASK_VALUE_FIELD.label = 1
SAIDRPCSAIDASK_VALUE_FIELD.has_default_value = false
SAIDRPCSAIDASK_VALUE_FIELD.default_value = nil
SAIDRPCSAIDASK_VALUE_FIELD.message_type = SAIDSAIDDATA
SAIDRPCSAIDASK_VALUE_FIELD.type = 11
SAIDRPCSAIDASK_VALUE_FIELD.cpp_type = 10

SAIDRPCSAIDASK.name = "SaidRpcSaidAsk"
SAIDRPCSAIDASK.full_name = ".SaidRpcSaidAsk"
SAIDRPCSAIDASK.nested_types = {}
SAIDRPCSAIDASK.enum_types = {}
SAIDRPCSAIDASK.fields = {SAIDRPCSAIDASK_VALUE_FIELD}
SAIDRPCSAIDASK.is_extendable = false
SAIDRPCSAIDASK.extensions = {}
SAIDRPCSAIDREPLY_RESULT_FIELD.name = "Result"
SAIDRPCSAIDREPLY_RESULT_FIELD.full_name = ".SaidRpcSaidReply.Result"
SAIDRPCSAIDREPLY_RESULT_FIELD.number = 1
SAIDRPCSAIDREPLY_RESULT_FIELD.index = 0
SAIDRPCSAIDREPLY_RESULT_FIELD.label = 1
SAIDRPCSAIDREPLY_RESULT_FIELD.has_default_value = true
SAIDRPCSAIDREPLY_RESULT_FIELD.default_value = -9999
SAIDRPCSAIDREPLY_RESULT_FIELD.type = 17
SAIDRPCSAIDREPLY_RESULT_FIELD.cpp_type = 1

SAIDRPCSAIDREPLY_VALUE_FIELD.name = "Value"
SAIDRPCSAIDREPLY_VALUE_FIELD.full_name = ".SaidRpcSaidReply.Value"
SAIDRPCSAIDREPLY_VALUE_FIELD.number = 2
SAIDRPCSAIDREPLY_VALUE_FIELD.index = 1
SAIDRPCSAIDREPLY_VALUE_FIELD.label = 1
SAIDRPCSAIDREPLY_VALUE_FIELD.has_default_value = false
SAIDRPCSAIDREPLY_VALUE_FIELD.default_value = nil
SAIDRPCSAIDREPLY_VALUE_FIELD.message_type = SAIDSAIDDATA
SAIDRPCSAIDREPLY_VALUE_FIELD.type = 11
SAIDRPCSAIDREPLY_VALUE_FIELD.cpp_type = 10

SAIDRPCSAIDREPLY.name = "SaidRpcSaidReply"
SAIDRPCSAIDREPLY.full_name = ".SaidRpcSaidReply"
SAIDRPCSAIDREPLY.nested_types = {}
SAIDRPCSAIDREPLY.enum_types = {}
SAIDRPCSAIDREPLY.fields = {SAIDRPCSAIDREPLY_RESULT_FIELD, SAIDRPCSAIDREPLY_VALUE_FIELD}
SAIDRPCSAIDREPLY.is_extendable = false
SAIDRPCSAIDREPLY.extensions = {}
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.name = "Value"
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.full_name = ".SaidRpcSaidBroadcasNotify.Value"
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.number = 1
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.index = 0
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.label = 1
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.has_default_value = false
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.default_value = nil
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.message_type = SAIDSAIDDATA
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.type = 11
SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD.cpp_type = 10

SAIDRPCSAIDBROADCASNOTIFY.name = "SaidRpcSaidBroadcasNotify"
SAIDRPCSAIDBROADCASNOTIFY.full_name = ".SaidRpcSaidBroadcasNotify"
SAIDRPCSAIDBROADCASNOTIFY.nested_types = {}
SAIDRPCSAIDBROADCASNOTIFY.enum_types = {}
SAIDRPCSAIDBROADCASNOTIFY.fields = {SAIDRPCSAIDBROADCASNOTIFY_VALUE_FIELD}
SAIDRPCSAIDBROADCASNOTIFY.is_extendable = false
SAIDRPCSAIDBROADCASNOTIFY.extensions = {}
SAIDSAIDDATA_CHANNEL_FIELD.name = "Channel"
SAIDSAIDDATA_CHANNEL_FIELD.full_name = ".SaidSaidData.Channel"
SAIDSAIDDATA_CHANNEL_FIELD.number = 1
SAIDSAIDDATA_CHANNEL_FIELD.index = 0
SAIDSAIDDATA_CHANNEL_FIELD.label = 1
SAIDSAIDDATA_CHANNEL_FIELD.has_default_value = true
SAIDSAIDDATA_CHANNEL_FIELD.default_value = -1
SAIDSAIDDATA_CHANNEL_FIELD.type = 17
SAIDSAIDDATA_CHANNEL_FIELD.cpp_type = 1

SAIDSAIDDATA_CONTENT_FIELD.name = "Content"
SAIDSAIDDATA_CONTENT_FIELD.full_name = ".SaidSaidData.Content"
SAIDSAIDDATA_CONTENT_FIELD.number = 2
SAIDSAIDDATA_CONTENT_FIELD.index = 1
SAIDSAIDDATA_CONTENT_FIELD.label = 1
SAIDSAIDDATA_CONTENT_FIELD.has_default_value = false
SAIDSAIDDATA_CONTENT_FIELD.default_value = ""
SAIDSAIDDATA_CONTENT_FIELD.type = 9
SAIDSAIDDATA_CONTENT_FIELD.cpp_type = 9

SAIDSAIDDATA_WHO_FIELD.name = "Who"
SAIDSAIDDATA_WHO_FIELD.full_name = ".SaidSaidData.Who"
SAIDSAIDDATA_WHO_FIELD.number = 3
SAIDSAIDDATA_WHO_FIELD.index = 2
SAIDSAIDDATA_WHO_FIELD.label = 1
SAIDSAIDDATA_WHO_FIELD.has_default_value = false
SAIDSAIDDATA_WHO_FIELD.default_value = nil
SAIDSAIDDATA_WHO_FIELD.message_type = PUBLICSTRUCT_PB_SMALLUSER
SAIDSAIDDATA_WHO_FIELD.type = 11
SAIDSAIDDATA_WHO_FIELD.cpp_type = 10

SAIDSAIDDATA_TO_FIELD.name = "To"
SAIDSAIDDATA_TO_FIELD.full_name = ".SaidSaidData.To"
SAIDSAIDDATA_TO_FIELD.number = 4
SAIDSAIDDATA_TO_FIELD.index = 3
SAIDSAIDDATA_TO_FIELD.label = 1
SAIDSAIDDATA_TO_FIELD.has_default_value = false
SAIDSAIDDATA_TO_FIELD.default_value = nil
SAIDSAIDDATA_TO_FIELD.message_type = PUBLICSTRUCT_PB_SMALLUSER
SAIDSAIDDATA_TO_FIELD.type = 11
SAIDSAIDDATA_TO_FIELD.cpp_type = 10

SAIDSAIDDATA_BIGTYPE_FIELD.name = "BigType"
SAIDSAIDDATA_BIGTYPE_FIELD.full_name = ".SaidSaidData.BigType"
SAIDSAIDDATA_BIGTYPE_FIELD.number = 5
SAIDSAIDDATA_BIGTYPE_FIELD.index = 4
SAIDSAIDDATA_BIGTYPE_FIELD.label = 1
SAIDSAIDDATA_BIGTYPE_FIELD.has_default_value = true
SAIDSAIDDATA_BIGTYPE_FIELD.default_value = 0
SAIDSAIDDATA_BIGTYPE_FIELD.type = 17
SAIDSAIDDATA_BIGTYPE_FIELD.cpp_type = 1

SAIDSAIDDATA_SMALLTYPE_FIELD.name = "SmallType"
SAIDSAIDDATA_SMALLTYPE_FIELD.full_name = ".SaidSaidData.SmallType"
SAIDSAIDDATA_SMALLTYPE_FIELD.number = 6
SAIDSAIDDATA_SMALLTYPE_FIELD.index = 5
SAIDSAIDDATA_SMALLTYPE_FIELD.label = 1
SAIDSAIDDATA_SMALLTYPE_FIELD.has_default_value = true
SAIDSAIDDATA_SMALLTYPE_FIELD.default_value = 0
SAIDSAIDDATA_SMALLTYPE_FIELD.type = 17
SAIDSAIDDATA_SMALLTYPE_FIELD.cpp_type = 1

SAIDSAIDDATA_ID_FIELD.name = "ID"
SAIDSAIDDATA_ID_FIELD.full_name = ".SaidSaidData.ID"
SAIDSAIDDATA_ID_FIELD.number = 7
SAIDSAIDDATA_ID_FIELD.index = 6
SAIDSAIDDATA_ID_FIELD.label = 1
SAIDSAIDDATA_ID_FIELD.has_default_value = true
SAIDSAIDDATA_ID_FIELD.default_value = -1
SAIDSAIDDATA_ID_FIELD.type = 18
SAIDSAIDDATA_ID_FIELD.cpp_type = 2

SAIDSAIDDATA.name = "SaidSaidData"
SAIDSAIDDATA.full_name = ".SaidSaidData"
SAIDSAIDDATA.nested_types = {}
SAIDSAIDDATA.enum_types = {}
SAIDSAIDDATA.fields = {SAIDSAIDDATA_CHANNEL_FIELD, SAIDSAIDDATA_CONTENT_FIELD, SAIDSAIDDATA_WHO_FIELD, SAIDSAIDDATA_TO_FIELD, SAIDSAIDDATA_BIGTYPE_FIELD, SAIDSAIDDATA_SMALLTYPE_FIELD, SAIDSAIDDATA_ID_FIELD}
SAIDSAIDDATA.is_extendable = false
SAIDSAIDDATA.extensions = {}

SaidRpcSaidAsk = protobuf.Message(SAIDRPCSAIDASK)
SaidRpcSaidBroadcasNotify = protobuf.Message(SAIDRPCSAIDBROADCASNOTIFY)
SaidRpcSaidReply = protobuf.Message(SAIDRPCSAIDREPLY)
SaidSaidData = protobuf.Message(SAIDSAIDDATA)

