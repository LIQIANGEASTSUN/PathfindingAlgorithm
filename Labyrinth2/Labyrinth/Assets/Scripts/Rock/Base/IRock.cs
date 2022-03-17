using UnityEngine;

public interface IRock
{
    void Begin(Vector2 pos);
    void Move(Vector2 pos, float percentage);
    void End(Vector2 pos);
}
