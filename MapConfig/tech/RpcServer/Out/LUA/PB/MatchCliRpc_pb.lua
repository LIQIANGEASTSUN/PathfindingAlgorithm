-- Generated By protoc-gen-lua Do not Edit
local protobuf = require "protobuf"
local PublicStruct_pb = require("PublicStruct_pb")
module('MatchCliRpc_pb')


local MATCHUSERMESSAGE = protobuf.Descriptor();
local MATCHUSERMESSAGE_UID_FIELD = protobuf.FieldDescriptor();
local MATCHUSERMESSAGE_HEAD_FIELD = protobuf.FieldDescriptor();
local MATCHUSERMESSAGE_NICKNAME_FIELD = protobuf.FieldDescriptor();
local MATCHUSERMESSAGE_RANK_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSTARTMATCHASK = protobuf.Descriptor();
local MATCHRPCSTARTMATCHREPLY = protobuf.Descriptor();
local MATCHRPCSTARTMATCHREPLY_RESULT_FIELD = protobuf.FieldDescriptor();
local MATCHRPCINVITATIONASK = protobuf.Descriptor();
local MATCHRPCINVITATIONASK_UID_FIELD = protobuf.FieldDescriptor();
local MATCHRPCINVITATIONREPLY = protobuf.Descriptor();
local MATCHRPCINVITATIONREPLY_RESULT_FIELD = protobuf.FieldDescriptor();
local MATCHRPCINVITATIONREPLY_UID_FIELD = protobuf.FieldDescriptor();
local MATCHRPCMATCHBROADCASNOTIFY = protobuf.Descriptor();
local MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD = protobuf.FieldDescriptor();
local MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD = protobuf.FieldDescriptor();
local MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD = protobuf.FieldDescriptor();
local MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD = protobuf.FieldDescriptor();
local MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSTARTSELECTNOTIFY = protobuf.Descriptor();
local MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSELECTHEROBROADCASNOTIFY = protobuf.Descriptor();
local MATCHRPCSELECTHERONOTIFY = protobuf.Descriptor();
local MATCHRPCSELECTHERONOTIFY_HEROID_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSELECTHERONOTIFY_UID_FIELD = protobuf.FieldDescriptor();
local MATCHRPCAGREEINVITATIONNOTIFY = protobuf.Descriptor();
local MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD = protobuf.FieldDescriptor();
local MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD = protobuf.FieldDescriptor();
local MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD = protobuf.FieldDescriptor();
local MATCHRPCSTARTGAMENOTIFY = protobuf.Descriptor();

MATCHUSERMESSAGE_UID_FIELD.name = "Uid"
MATCHUSERMESSAGE_UID_FIELD.full_name = ".MatchUserMessage.Uid"
MATCHUSERMESSAGE_UID_FIELD.number = 2
MATCHUSERMESSAGE_UID_FIELD.index = 0
MATCHUSERMESSAGE_UID_FIELD.label = 1
MATCHUSERMESSAGE_UID_FIELD.has_default_value = true
MATCHUSERMESSAGE_UID_FIELD.default_value = -1
MATCHUSERMESSAGE_UID_FIELD.type = 18
MATCHUSERMESSAGE_UID_FIELD.cpp_type = 2

MATCHUSERMESSAGE_HEAD_FIELD.name = "Head"
MATCHUSERMESSAGE_HEAD_FIELD.full_name = ".MatchUserMessage.Head"
MATCHUSERMESSAGE_HEAD_FIELD.number = 3
MATCHUSERMESSAGE_HEAD_FIELD.index = 1
MATCHUSERMESSAGE_HEAD_FIELD.label = 1
MATCHUSERMESSAGE_HEAD_FIELD.has_default_value = false
MATCHUSERMESSAGE_HEAD_FIELD.default_value = ""
MATCHUSERMESSAGE_HEAD_FIELD.type = 9
MATCHUSERMESSAGE_HEAD_FIELD.cpp_type = 9

MATCHUSERMESSAGE_NICKNAME_FIELD.name = "NickName"
MATCHUSERMESSAGE_NICKNAME_FIELD.full_name = ".MatchUserMessage.NickName"
MATCHUSERMESSAGE_NICKNAME_FIELD.number = 4
MATCHUSERMESSAGE_NICKNAME_FIELD.index = 2
MATCHUSERMESSAGE_NICKNAME_FIELD.label = 1
MATCHUSERMESSAGE_NICKNAME_FIELD.has_default_value = false
MATCHUSERMESSAGE_NICKNAME_FIELD.default_value = ""
MATCHUSERMESSAGE_NICKNAME_FIELD.type = 9
MATCHUSERMESSAGE_NICKNAME_FIELD.cpp_type = 9

MATCHUSERMESSAGE_RANK_FIELD.name = "Rank"
MATCHUSERMESSAGE_RANK_FIELD.full_name = ".MatchUserMessage.Rank"
MATCHUSERMESSAGE_RANK_FIELD.number = 5
MATCHUSERMESSAGE_RANK_FIELD.index = 3
MATCHUSERMESSAGE_RANK_FIELD.label = 1
MATCHUSERMESSAGE_RANK_FIELD.has_default_value = true
MATCHUSERMESSAGE_RANK_FIELD.default_value = 0
MATCHUSERMESSAGE_RANK_FIELD.type = 17
MATCHUSERMESSAGE_RANK_FIELD.cpp_type = 1

MATCHUSERMESSAGE.name = "MatchUserMessage"
MATCHUSERMESSAGE.full_name = ".MatchUserMessage"
MATCHUSERMESSAGE.nested_types = {}
MATCHUSERMESSAGE.enum_types = {}
MATCHUSERMESSAGE.fields = {MATCHUSERMESSAGE_UID_FIELD, MATCHUSERMESSAGE_HEAD_FIELD, MATCHUSERMESSAGE_NICKNAME_FIELD, MATCHUSERMESSAGE_RANK_FIELD}
MATCHUSERMESSAGE.is_extendable = false
MATCHUSERMESSAGE.extensions = {}
MATCHRPCSTARTMATCHASK.name = "MatchRpcStartMatchAsk"
MATCHRPCSTARTMATCHASK.full_name = ".MatchRpcStartMatchAsk"
MATCHRPCSTARTMATCHASK.nested_types = {}
MATCHRPCSTARTMATCHASK.enum_types = {}
MATCHRPCSTARTMATCHASK.fields = {}
MATCHRPCSTARTMATCHASK.is_extendable = false
MATCHRPCSTARTMATCHASK.extensions = {}
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.name = "Result"
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.full_name = ".MatchRpcStartMatchReply.Result"
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.number = 1
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.index = 0
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.label = 1
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.has_default_value = true
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.default_value = -9999
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.type = 17
MATCHRPCSTARTMATCHREPLY_RESULT_FIELD.cpp_type = 1

MATCHRPCSTARTMATCHREPLY.name = "MatchRpcStartMatchReply"
MATCHRPCSTARTMATCHREPLY.full_name = ".MatchRpcStartMatchReply"
MATCHRPCSTARTMATCHREPLY.nested_types = {}
MATCHRPCSTARTMATCHREPLY.enum_types = {}
MATCHRPCSTARTMATCHREPLY.fields = {MATCHRPCSTARTMATCHREPLY_RESULT_FIELD}
MATCHRPCSTARTMATCHREPLY.is_extendable = false
MATCHRPCSTARTMATCHREPLY.extensions = {}
MATCHRPCINVITATIONASK_UID_FIELD.name = "Uid"
MATCHRPCINVITATIONASK_UID_FIELD.full_name = ".MatchRpcInvitationAsk.Uid"
MATCHRPCINVITATIONASK_UID_FIELD.number = 1
MATCHRPCINVITATIONASK_UID_FIELD.index = 0
MATCHRPCINVITATIONASK_UID_FIELD.label = 1
MATCHRPCINVITATIONASK_UID_FIELD.has_default_value = true
MATCHRPCINVITATIONASK_UID_FIELD.default_value = -1
MATCHRPCINVITATIONASK_UID_FIELD.type = 18
MATCHRPCINVITATIONASK_UID_FIELD.cpp_type = 2

MATCHRPCINVITATIONASK.name = "MatchRpcInvitationAsk"
MATCHRPCINVITATIONASK.full_name = ".MatchRpcInvitationAsk"
MATCHRPCINVITATIONASK.nested_types = {}
MATCHRPCINVITATIONASK.enum_types = {}
MATCHRPCINVITATIONASK.fields = {MATCHRPCINVITATIONASK_UID_FIELD}
MATCHRPCINVITATIONASK.is_extendable = false
MATCHRPCINVITATIONASK.extensions = {}
MATCHRPCINVITATIONREPLY_RESULT_FIELD.name = "Result"
MATCHRPCINVITATIONREPLY_RESULT_FIELD.full_name = ".MatchRpcInvitationReply.Result"
MATCHRPCINVITATIONREPLY_RESULT_FIELD.number = 1
MATCHRPCINVITATIONREPLY_RESULT_FIELD.index = 0
MATCHRPCINVITATIONREPLY_RESULT_FIELD.label = 1
MATCHRPCINVITATIONREPLY_RESULT_FIELD.has_default_value = true
MATCHRPCINVITATIONREPLY_RESULT_FIELD.default_value = -9999
MATCHRPCINVITATIONREPLY_RESULT_FIELD.type = 17
MATCHRPCINVITATIONREPLY_RESULT_FIELD.cpp_type = 1

MATCHRPCINVITATIONREPLY_UID_FIELD.name = "Uid"
MATCHRPCINVITATIONREPLY_UID_FIELD.full_name = ".MatchRpcInvitationReply.Uid"
MATCHRPCINVITATIONREPLY_UID_FIELD.number = 2
MATCHRPCINVITATIONREPLY_UID_FIELD.index = 1
MATCHRPCINVITATIONREPLY_UID_FIELD.label = 1
MATCHRPCINVITATIONREPLY_UID_FIELD.has_default_value = true
MATCHRPCINVITATIONREPLY_UID_FIELD.default_value = -1
MATCHRPCINVITATIONREPLY_UID_FIELD.type = 18
MATCHRPCINVITATIONREPLY_UID_FIELD.cpp_type = 2

MATCHRPCINVITATIONREPLY.name = "MatchRpcInvitationReply"
MATCHRPCINVITATIONREPLY.full_name = ".MatchRpcInvitationReply"
MATCHRPCINVITATIONREPLY.nested_types = {}
MATCHRPCINVITATIONREPLY.enum_types = {}
MATCHRPCINVITATIONREPLY.fields = {MATCHRPCINVITATIONREPLY_RESULT_FIELD, MATCHRPCINVITATIONREPLY_UID_FIELD}
MATCHRPCINVITATIONREPLY.is_extendable = false
MATCHRPCINVITATIONREPLY.extensions = {}
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.name = "Type"
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.full_name = ".MatchRpcMatchBroadcasNotify.Type"
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.number = 1
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.index = 0
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.label = 1
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.has_default_value = true
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.default_value = 1
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.type = 17
MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD.cpp_type = 1

MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.name = "TimeStart"
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.full_name = ".MatchRpcMatchBroadcasNotify.TimeStart"
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.number = 2
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.index = 1
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.label = 1
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.has_default_value = true
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.default_value = -1
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.type = 17
MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD.cpp_type = 1

MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.name = "TimeEnd"
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.full_name = ".MatchRpcMatchBroadcasNotify.TimeEnd"
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.number = 3
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.index = 2
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.label = 1
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.has_default_value = true
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.default_value = -1
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.type = 17
MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD.cpp_type = 1

MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.name = "Timer"
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.full_name = ".MatchRpcMatchBroadcasNotify.Timer"
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.number = 4
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.index = 3
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.label = 1
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.has_default_value = true
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.default_value = -1
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.type = 17
MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD.cpp_type = 1

MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.name = "UMess"
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.full_name = ".MatchRpcMatchBroadcasNotify.UMess"
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.number = 5
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.index = 4
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.label = 3
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.has_default_value = false
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.default_value = {}
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.message_type = MATCHUSERMESSAGE
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.type = 11
MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD.cpp_type = 10

MATCHRPCMATCHBROADCASNOTIFY.name = "MatchRpcMatchBroadcasNotify"
MATCHRPCMATCHBROADCASNOTIFY.full_name = ".MatchRpcMatchBroadcasNotify"
MATCHRPCMATCHBROADCASNOTIFY.nested_types = {}
MATCHRPCMATCHBROADCASNOTIFY.enum_types = {}
MATCHRPCMATCHBROADCASNOTIFY.fields = {MATCHRPCMATCHBROADCASNOTIFY_TYPE_FIELD, MATCHRPCMATCHBROADCASNOTIFY_TIMESTART_FIELD, MATCHRPCMATCHBROADCASNOTIFY_TIMEEND_FIELD, MATCHRPCMATCHBROADCASNOTIFY_TIMER_FIELD, MATCHRPCMATCHBROADCASNOTIFY_UMESS_FIELD}
MATCHRPCMATCHBROADCASNOTIFY.is_extendable = false
MATCHRPCMATCHBROADCASNOTIFY.extensions = {}
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.name = "TimeStart"
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.full_name = ".MatchRpcStartSelectNotify.TimeStart"
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.number = 1
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.index = 0
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.label = 1
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.has_default_value = true
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.default_value = -1
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.type = 17
MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD.cpp_type = 1

MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.name = "TimeEnd"
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.full_name = ".MatchRpcStartSelectNotify.TimeEnd"
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.number = 2
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.index = 1
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.label = 1
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.has_default_value = true
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.default_value = -1
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.type = 17
MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD.cpp_type = 1

MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.name = "MyUMess"
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.full_name = ".MatchRpcStartSelectNotify.MyUMess"
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.number = 3
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.index = 2
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.label = 3
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.has_default_value = false
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.default_value = {}
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.message_type = MATCHUSERMESSAGE
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.type = 11
MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD.cpp_type = 10

MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.name = "OtherUMess"
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.full_name = ".MatchRpcStartSelectNotify.OtherUMess"
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.number = 4
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.index = 3
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.label = 3
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.has_default_value = false
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.default_value = {}
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.message_type = MATCHUSERMESSAGE
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.type = 11
MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD.cpp_type = 10

MATCHRPCSTARTSELECTNOTIFY.name = "MatchRpcStartSelectNotify"
MATCHRPCSTARTSELECTNOTIFY.full_name = ".MatchRpcStartSelectNotify"
MATCHRPCSTARTSELECTNOTIFY.nested_types = {}
MATCHRPCSTARTSELECTNOTIFY.enum_types = {}
MATCHRPCSTARTSELECTNOTIFY.fields = {MATCHRPCSTARTSELECTNOTIFY_TIMESTART_FIELD, MATCHRPCSTARTSELECTNOTIFY_TIMEEND_FIELD, MATCHRPCSTARTSELECTNOTIFY_MYUMESS_FIELD, MATCHRPCSTARTSELECTNOTIFY_OTHERUMESS_FIELD}
MATCHRPCSTARTSELECTNOTIFY.is_extendable = false
MATCHRPCSTARTSELECTNOTIFY.extensions = {}
MATCHRPCSELECTHEROBROADCASNOTIFY.name = "MatchRpcSelectHeroBroadcasNotify"
MATCHRPCSELECTHEROBROADCASNOTIFY.full_name = ".MatchRpcSelectHeroBroadcasNotify"
MATCHRPCSELECTHEROBROADCASNOTIFY.nested_types = {}
MATCHRPCSELECTHEROBROADCASNOTIFY.enum_types = {}
MATCHRPCSELECTHEROBROADCASNOTIFY.fields = {}
MATCHRPCSELECTHEROBROADCASNOTIFY.is_extendable = false
MATCHRPCSELECTHEROBROADCASNOTIFY.extensions = {}
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.name = "HeroID"
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.full_name = ".MatchRpcSelectHeroNotify.HeroID"
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.number = 1
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.index = 0
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.label = 1
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.has_default_value = true
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.default_value = -1
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.type = 17
MATCHRPCSELECTHERONOTIFY_HEROID_FIELD.cpp_type = 1

MATCHRPCSELECTHERONOTIFY_UID_FIELD.name = "Uid"
MATCHRPCSELECTHERONOTIFY_UID_FIELD.full_name = ".MatchRpcSelectHeroNotify.Uid"
MATCHRPCSELECTHERONOTIFY_UID_FIELD.number = 2
MATCHRPCSELECTHERONOTIFY_UID_FIELD.index = 1
MATCHRPCSELECTHERONOTIFY_UID_FIELD.label = 1
MATCHRPCSELECTHERONOTIFY_UID_FIELD.has_default_value = true
MATCHRPCSELECTHERONOTIFY_UID_FIELD.default_value = -1
MATCHRPCSELECTHERONOTIFY_UID_FIELD.type = 18
MATCHRPCSELECTHERONOTIFY_UID_FIELD.cpp_type = 2

MATCHRPCSELECTHERONOTIFY.name = "MatchRpcSelectHeroNotify"
MATCHRPCSELECTHERONOTIFY.full_name = ".MatchRpcSelectHeroNotify"
MATCHRPCSELECTHERONOTIFY.nested_types = {}
MATCHRPCSELECTHERONOTIFY.enum_types = {}
MATCHRPCSELECTHERONOTIFY.fields = {MATCHRPCSELECTHERONOTIFY_HEROID_FIELD, MATCHRPCSELECTHERONOTIFY_UID_FIELD}
MATCHRPCSELECTHERONOTIFY.is_extendable = false
MATCHRPCSELECTHERONOTIFY.extensions = {}
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.name = "Uid"
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.full_name = ".MatchRpcAgreeInvitationNotify.Uid"
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.number = 1
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.index = 0
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.label = 1
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.has_default_value = true
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.default_value = -1
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.type = 18
MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD.cpp_type = 2

MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.name = "IsAgree"
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.full_name = ".MatchRpcAgreeInvitationNotify.IsAgree"
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.number = 2
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.index = 1
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.label = 1
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.has_default_value = true
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.default_value = 0
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.type = 17
MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD.cpp_type = 1

MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.name = "Type"
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.full_name = ".MatchRpcAgreeInvitationNotify.Type"
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.number = 3
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.index = 2
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.label = 1
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.has_default_value = true
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.default_value = 0
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.type = 17
MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD.cpp_type = 1

MATCHRPCAGREEINVITATIONNOTIFY.name = "MatchRpcAgreeInvitationNotify"
MATCHRPCAGREEINVITATIONNOTIFY.full_name = ".MatchRpcAgreeInvitationNotify"
MATCHRPCAGREEINVITATIONNOTIFY.nested_types = {}
MATCHRPCAGREEINVITATIONNOTIFY.enum_types = {}
MATCHRPCAGREEINVITATIONNOTIFY.fields = {MATCHRPCAGREEINVITATIONNOTIFY_UID_FIELD, MATCHRPCAGREEINVITATIONNOTIFY_ISAGREE_FIELD, MATCHRPCAGREEINVITATIONNOTIFY_TYPE_FIELD}
MATCHRPCAGREEINVITATIONNOTIFY.is_extendable = false
MATCHRPCAGREEINVITATIONNOTIFY.extensions = {}
MATCHRPCSTARTGAMENOTIFY.name = "MatchRpcStartGameNotify"
MATCHRPCSTARTGAMENOTIFY.full_name = ".MatchRpcStartGameNotify"
MATCHRPCSTARTGAMENOTIFY.nested_types = {}
MATCHRPCSTARTGAMENOTIFY.enum_types = {}
MATCHRPCSTARTGAMENOTIFY.fields = {}
MATCHRPCSTARTGAMENOTIFY.is_extendable = false
MATCHRPCSTARTGAMENOTIFY.extensions = {}

MatchRpcAgreeInvitationNotify = protobuf.Message(MATCHRPCAGREEINVITATIONNOTIFY)
MatchRpcInvitationAsk = protobuf.Message(MATCHRPCINVITATIONASK)
MatchRpcInvitationReply = protobuf.Message(MATCHRPCINVITATIONREPLY)
MatchRpcMatchBroadcasNotify = protobuf.Message(MATCHRPCMATCHBROADCASNOTIFY)
MatchRpcSelectHeroBroadcasNotify = protobuf.Message(MATCHRPCSELECTHEROBROADCASNOTIFY)
MatchRpcSelectHeroNotify = protobuf.Message(MATCHRPCSELECTHERONOTIFY)
MatchRpcStartGameNotify = protobuf.Message(MATCHRPCSTARTGAMENOTIFY)
MatchRpcStartMatchAsk = protobuf.Message(MATCHRPCSTARTMATCHASK)
MatchRpcStartMatchReply = protobuf.Message(MATCHRPCSTARTMATCHREPLY)
MatchRpcStartSelectNotify = protobuf.Message(MATCHRPCSTARTSELECTNOTIFY)
MatchUserMessage = protobuf.Message(MATCHUSERMESSAGE)
