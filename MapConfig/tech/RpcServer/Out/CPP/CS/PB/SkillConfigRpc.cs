//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

// Generated from: SkillConfigCliRpc.proto
// Note: requires additional types generated from: PublicStruct.proto
namespace GenPB
{
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillConfigRpcsyncNotify")]
  public partial class SkillConfigRpcsyncNotify : global::ProtoBuf.IExtensible
  {
    public SkillConfigRpcsyncNotify() {}
    
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillConfigSkillPhase")]
  public partial class SkillConfigSkillPhase : global::ProtoBuf.IExtensible
  {
    public SkillConfigSkillPhase() {}
    
    private int _SkillPhaseType = (int)0;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"SkillPhaseType", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int SkillPhaseType
    {
      get { return _SkillPhaseType; }
      set { _SkillPhaseType = value; }
    }
    private int _TimeLength = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"TimeLength", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int TimeLength
    {
      get { return _TimeLength; }
      set { _TimeLength = value; }
    }
    private readonly global::System.Collections.Generic.List<SkillConfigSkillCustomEvent> _CustomEvetnList = new global::System.Collections.Generic.List<SkillConfigSkillCustomEvent>();
    [global::ProtoBuf.ProtoMember(7, Name=@"CustomEvetnList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<SkillConfigSkillCustomEvent> CustomEvetnList
    {
      get { return _CustomEvetnList; }
    }
  
    private readonly global::System.Collections.Generic.List<SkillConfigBulletTrajectoryEvent> _BulletTrajectoryEventList = new global::System.Collections.Generic.List<SkillConfigBulletTrajectoryEvent>();
    [global::ProtoBuf.ProtoMember(8, Name=@"BulletTrajectoryEventList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<SkillConfigBulletTrajectoryEvent> BulletTrajectoryEventList
    {
      get { return _BulletTrajectoryEventList; }
    }
  
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillConfigSkillInfo")]
  public partial class SkillConfigSkillInfo : global::ProtoBuf.IExtensible
  {
    public SkillConfigSkillInfo() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(8, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _HandleType = (int)0;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"HandleType", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int HandleType
    {
      get { return _HandleType; }
      set { _HandleType = value; }
    }
    private int _SkillTime = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"SkillTime", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int SkillTime
    {
      get { return _SkillTime; }
      set { _SkillTime = value; }
    }
    private int _FocoTime = (int)-1;
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"FocoTime", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int FocoTime
    {
      get { return _FocoTime; }
      set { _FocoTime = value; }
    }
    private readonly global::System.Collections.Generic.List<SkillConfigSkillPhase> _SkillPhaseList = new global::System.Collections.Generic.List<SkillConfigSkillPhase>();
    [global::ProtoBuf.ProtoMember(7, Name=@"SkillPhaseList", DataFormat = global::ProtoBuf.DataFormat.Default)]
    public global::System.Collections.Generic.List<SkillConfigSkillPhase> SkillPhaseList
    {
      get { return _SkillPhaseList; }
    }
  
    private bool _Unbroken = (bool)false;
    [global::ProtoBuf.ProtoMember(10, IsRequired = false, Name=@"Unbroken", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue((bool)false)]
    public bool Unbroken
    {
      get { return _Unbroken; }
      set { _Unbroken = value; }
    }
    private int _UseTimes = (int)-1;
    [global::ProtoBuf.ProtoMember(11, IsRequired = false, Name=@"UseTimes", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int UseTimes
    {
      get { return _UseTimes; }
      set { _UseTimes = value; }
    }
    private SkillConfigCameraChangeInfo _CameraData = null;
    [global::ProtoBuf.ProtoMember(16, IsRequired = false, Name=@"CameraData", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public SkillConfigCameraChangeInfo CameraData
    {
      get { return _CameraData; }
      set { _CameraData = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillConfigSkillEventBase")]
  public partial class SkillConfigSkillEventBase : global::ProtoBuf.IExtensible
  {
    public SkillConfigSkillEventBase() {}
    
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _EventType = (int)0;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"EventType", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int EventType
    {
      get { return _EventType; }
      set { _EventType = value; }
    }
    private int _Start = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"Start", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Start
    {
      get { return _Start; }
      set { _Start = value; }
    }
    private int _EventLength = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"EventLength", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int EventLength
    {
      get { return _EventLength; }
      set { _EventLength = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillConfigSkillCustomEvent")]
  public partial class SkillConfigSkillCustomEvent : global::ProtoBuf.IExtensible
  {
    public SkillConfigSkillCustomEvent() {}
    
    private SkillConfigSkillEventBase _EventBase = null;
    [global::ProtoBuf.ProtoMember(17, IsRequired = false, Name=@"EventBase", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public SkillConfigSkillEventBase EventBase
    {
      get { return _EventBase; }
      set { _EventBase = value; }
    }
    private string _FileName = "";
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"FileName", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue("")]
    public string FileName
    {
      get { return _FileName; }
      set { _FileName = value; }
    }
    private int _ModelMountPoint = (int)0;
    [global::ProtoBuf.ProtoMember(7, IsRequired = false, Name=@"ModelMountPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int ModelMountPoint
    {
      get { return _ModelMountPoint; }
      set { _ModelMountPoint = value; }
    }
    private int _WeaponMountPoint = (int)0;
    [global::ProtoBuf.ProtoMember(8, IsRequired = false, Name=@"WeaponMountPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int WeaponMountPoint
    {
      get { return _WeaponMountPoint; }
      set { _WeaponMountPoint = value; }
    }
    private int _EffectMountPoint = (int)0;
    [global::ProtoBuf.ProtoMember(12, IsRequired = false, Name=@"EffectMountPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int EffectMountPoint
    {
      get { return _EffectMountPoint; }
      set { _EffectMountPoint = value; }
    }
    private bool _Loop = (bool)false;
    [global::ProtoBuf.ProtoMember(9, IsRequired = false, Name=@"Loop", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue((bool)false)]
    public bool Loop
    {
      get { return _Loop; }
      set { _Loop = value; }
    }
    private bool _WholeAnimation = (bool)false;
    [global::ProtoBuf.ProtoMember(10, IsRequired = false, Name=@"WholeAnimation", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue((bool)false)]
    public bool WholeAnimation
    {
      get { return _WholeAnimation; }
      set { _WholeAnimation = value; }
    }
    private float _OffsetX = (float)-1;
    [global::ProtoBuf.ProtoMember(14, IsRequired = false, Name=@"OffsetX", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float OffsetX
    {
      get { return _OffsetX; }
      set { _OffsetX = value; }
    }
    private float _OffsetY = (float)-1;
    [global::ProtoBuf.ProtoMember(15, IsRequired = false, Name=@"OffsetY", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float OffsetY
    {
      get { return _OffsetY; }
      set { _OffsetY = value; }
    }
    private float _OffsetZ = (float)-1;
    [global::ProtoBuf.ProtoMember(16, IsRequired = false, Name=@"OffsetZ", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float OffsetZ
    {
      get { return _OffsetZ; }
      set { _OffsetZ = value; }
    }
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(18, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _EffectRemove = (int)0;
    [global::ProtoBuf.ProtoMember(21, IsRequired = false, Name=@"EffectRemove", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int EffectRemove
    {
      get { return _EffectRemove; }
      set { _EffectRemove = value; }
    }
    private int _EffectRemoveTime = (int)-1;
    [global::ProtoBuf.ProtoMember(20, IsRequired = false, Name=@"EffectRemoveTime", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int EffectRemoveTime
    {
      get { return _EffectRemoveTime; }
      set { _EffectRemoveTime = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillConfigBulletTrajectoryEvent")]
  public partial class SkillConfigBulletTrajectoryEvent : global::ProtoBuf.IExtensible
  {
    public SkillConfigBulletTrajectoryEvent() {}
    
    private SkillConfigSkillEventBase _EventBase = null;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"EventBase", DataFormat = global::ProtoBuf.DataFormat.Default)]
    [global::System.ComponentModel.DefaultValue(null)]
    public SkillConfigSkillEventBase EventBase
    {
      get { return _EventBase; }
      set { _EventBase = value; }
    }
    private int _Id = (int)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"Id", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int Id
    {
      get { return _Id; }
      set { _Id = value; }
    }
    private int _ModelMountPoint = (int)0;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"ModelMountPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int ModelMountPoint
    {
      get { return _ModelMountPoint; }
      set { _ModelMountPoint = value; }
    }
    private int _WeaponMountPoint = (int)0;
    [global::ProtoBuf.ProtoMember(5, IsRequired = false, Name=@"WeaponMountPoint", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)0)]
    public int WeaponMountPoint
    {
      get { return _WeaponMountPoint; }
      set { _WeaponMountPoint = value; }
    }
    private float _OffsetX = (float)-1;
    [global::ProtoBuf.ProtoMember(6, IsRequired = false, Name=@"OffsetX", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float OffsetX
    {
      get { return _OffsetX; }
      set { _OffsetX = value; }
    }
    private float _OffsetY = (float)-1;
    [global::ProtoBuf.ProtoMember(7, IsRequired = false, Name=@"OffsetY", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float OffsetY
    {
      get { return _OffsetY; }
      set { _OffsetY = value; }
    }
    private float _OffsetZ = (float)-1;
    [global::ProtoBuf.ProtoMember(8, IsRequired = false, Name=@"OffsetZ", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float OffsetZ
    {
      get { return _OffsetZ; }
      set { _OffsetZ = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
  [global::System.Serializable, global::ProtoBuf.ProtoContract(Name=@"SkillConfigCameraChangeInfo")]
  public partial class SkillConfigCameraChangeInfo : global::ProtoBuf.IExtensible
  {
    public SkillConfigCameraChangeInfo() {}
    
    private int _CameraChangeStartTime = (int)-1;
    [global::ProtoBuf.ProtoMember(1, IsRequired = false, Name=@"CameraChangeStartTime", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int CameraChangeStartTime
    {
      get { return _CameraChangeStartTime; }
      set { _CameraChangeStartTime = value; }
    }
    private float _CameraFieldView = (float)-1;
    [global::ProtoBuf.ProtoMember(2, IsRequired = false, Name=@"CameraFieldView", DataFormat = global::ProtoBuf.DataFormat.FixedSize)]
    [global::System.ComponentModel.DefaultValue((float)-1)]
    public float CameraFieldView
    {
      get { return _CameraFieldView; }
      set { _CameraFieldView = value; }
    }
    private int _CameraChangeEndTime = (int)-1;
    [global::ProtoBuf.ProtoMember(3, IsRequired = false, Name=@"CameraChangeEndTime", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int CameraChangeEndTime
    {
      get { return _CameraChangeEndTime; }
      set { _CameraChangeEndTime = value; }
    }
    private int _CameraRecoverTime = (int)-1;
    [global::ProtoBuf.ProtoMember(4, IsRequired = false, Name=@"CameraRecoverTime", DataFormat = global::ProtoBuf.DataFormat.ZigZag)]
    [global::System.ComponentModel.DefaultValue((int)-1)]
    public int CameraRecoverTime
    {
      get { return _CameraRecoverTime; }
      set { _CameraRecoverTime = value; }
    }
    private global::ProtoBuf.IExtension extensionObject;
    global::ProtoBuf.IExtension global::ProtoBuf.IExtensible.GetExtensionObject(bool createIfMissing)
      { return global::ProtoBuf.Extensible.GetExtensionObject(ref extensionObject, createIfMissing); }
  }
  
}