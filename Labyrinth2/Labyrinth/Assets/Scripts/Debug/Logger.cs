#define LOG_IN_FILE

using UnityEngine;
using System.Collections;
using System;
using System.Text;
using System.Collections.Generic;

namespace ProDebug
{

    public class GameConstants
    {
        public static bool DEBUG_MODEL = true;
    }


    public static class Logger
    {

        private static void LogInFile(string log)
        {
#if LOG_IN_FILE
            if (!Debug.isDebugBuild && !Application.isEditor)
            {
                return;
            }

            if (Application.isMobilePlatform)
            {
                System.Console.WriteLine(log);
            }
#endif
        }

        public static string GetLogMsg(params object[] args)
        {
            string[] strArgs = new string[args.Length];
            for (int i = 0; i < args.Length; i++)
            {
                strArgs[i] = null != args[i] ? args[i].ToString() : "null";
            }
            string msg = string.Join(" ", strArgs);
            LogInFile(msg);
            return msg;
        }

        public static void Log(params object[] args)
        {
            //#if SHOW_DEBUG
            //            Debug.Log(GetLogMsg(args));
            //#endif
            if (GameConstants.DEBUG_MODEL)
                Debug.Log(GetLogMsg(args));
        }


        public static void LogError(params object[] args)
        {
            //#if SHOW_DEBUG
            //            Debug.LogError(GetLogMsg(args));
            //#endif
            if (GameConstants.DEBUG_MODEL)
            {
                string _error = GetLogMsg(args);
                Debug.LogError(_error);
            }
        }

        public static void LogError(ICollection arr)
        {
            if (GameConstants.DEBUG_MODEL)
            {
                StringBuilder sb = new StringBuilder();
                sb.Append("[");
                foreach (var item in arr)
                {
                    sb.Append(item.ToString());
                    sb.Append(",");
                }
                sb.Length -= 1;
                sb.Append("]");
                string _error = sb.ToString();
                Debug.LogError(_error);
            }
        }

        public static void LogCrash(params object[] args)
        {
            string str = GetLogMsg(args);
            LogError(str);
        }

        public static void LogWarning(params object[] args)
        {
            //#if SHOW_DEBUG
            //            Debug.LogWarning(GetLogMsg(args));
            //#endif
            if (GameConstants.DEBUG_MODEL)
                Debug.LogWarning(GetLogMsg(args));
        }

        public static string StrConcat(params object[] args)
        {
            if (args == null)
            {
                return string.Empty;
            }

            if (!GameConstants.DEBUG_MODEL)
            {
                return string.Empty;
            }

            string ret = string.Empty;

            for (int i = 0; i < args.Length; i++)
            {
                ret += args[i].ToString();
            }
            return ret;
        }

        public static string StrFormat(String format, params object[] args)
        {
            if (!GameConstants.DEBUG_MODEL)
            {
                return string.Empty;
            }

            return string.Format(format, args);
        }
    }

}

