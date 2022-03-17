using UnityEngine;

/// <summary>
/// UI相关工具类
/// </summary>
public class UIUtils : SingletonObject<UIUtils>
{
    /// <summary>
    /// 获取相对UI当前缩放的尺寸
    /// </summary>
    /// <param name="length">原始尺寸</param>
    /// <returns>缩放后的尺寸</returns>
    public float GetUIRelativeLength(float length)
    {
        Vector2 _designScreen = GameConstants.GAME_RESOLUTION;
        if (Screen.height * 1.0f / Screen.width <= _designScreen.y * 1.0f / _designScreen.x)
            return Screen.height / _designScreen.y * length;
        else
            return Screen.width / _designScreen.x * length;
    }

}
