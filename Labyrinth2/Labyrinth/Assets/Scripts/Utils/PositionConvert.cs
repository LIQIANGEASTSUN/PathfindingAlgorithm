using System.Collections;
using System.Collections.Generic;
using UnityEngine;

namespace Utility
{
    public class PositionConvert
    {

        public static Vector3 WorldToScreenPoint(Vector3 position)
        {
            if (null == Camera.main)
            {
                return Vector3.zero;
            }
            return Camera.main.WorldToScreenPoint(position);
        }

        public static Vector2 ScreenToUIPosition(RectTransform rectTransform, Vector2 scenePosition, Camera camera)
        {
            Vector3 targetUIPosition = Vector3.zero;
            if (RectTransformUtility.ScreenPointToWorldPointInRectangle(rectTransform, scenePosition, camera, out targetUIPosition))
            {

            }
            return targetUIPosition;
        }

        private static Camera uiCamera;
        private static GameObject uiRoot;
        public static Vector2 UIPositionToScreenPosition(Vector3 uiPosition)
        {
            if (null == uiCamera)
            {
                if (uiRoot == null)
                {
                    uiRoot = GameObject.Find("UIRoot");
                }
                uiCamera = uiRoot.GetComponent<Canvas>().worldCamera;
            }
            if (null == uiCamera)
            {
                Debug.LogError("UICamera is null");
                return Vector2.zero;
            }
            return uiCamera.WorldToScreenPoint(uiPosition);
        }
        public static Vector3 ScreenPositionToWorldPosition(Vector3 screenPosition)
        {
            if (null == uiCamera)
            {
                if (uiRoot == null)
                {
                    uiRoot = GameObject.Find("UIRoot");
                }
                uiCamera = uiRoot.GetComponent<Canvas>().worldCamera;
            }
            if (null == uiCamera)
            {
                Debug.LogError("UICamera is null");
                return Vector3.zero;
            }
            return uiCamera.ScreenToWorldPoint(screenPosition);
        }
    }
}
