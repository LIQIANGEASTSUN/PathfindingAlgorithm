using System;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;

/***
 * 
 * 表数据
 * 
 * 需要的功能类，需要自己持有相应数据
 * 
 * ***/
public partial class TableDatas
{

    public TableDatas()
    {
    }

    #region Control

    public static void LoadCsv(string tabName, string content)
    {
        if (content.Length == 0)
        {
            return;
        }
        int contentOffset = 0;
        int row = 0;
        //List<string> l = GameAssist.readCsvLine(content, ref contentOffset);
        if (!m_dicTab.ContainsKey(tabName))
        {
            m_dicTab.Add(tabName, new Dictionary<string, Dictionary<string, string>>());
        }
        int be = 0;
        List<string> k = new List<string>();
        while (true)
        {
            List<string> list = GameAssist.readCsvLine(content, ref contentOffset);
            if (list.Count == 0)
            {
                break;
            }
            if (be == 0)
            {
                for (int i = 0; i < list.Count; i++)
                {
                    if (null == m_dicTab[tabName])
                    {
                        m_dicTab[tabName] = new Dictionary<string, Dictionary<string, string>>();
                    }
                    if (!m_dicTab[tabName].ContainsKey(list[i]))
                    {
                        k.Add(list[i]);
                    }
                }
            }
            else
            {
                if (!m_dicTab[tabName].ContainsKey(list[0]))
                {
                    m_dicTab[tabName].Add(list[0], new Dictionary<string, string>());
                }
                if (k.Count < list.Count)
                {
                    ProDebug.Logger.LogError(ProDebug.Logger.StrConcat(tabName, "表错了, id为：", list[0]));
                    return;
                }
                for (int i = 0; i < list.Count; i++)
                {
                    if (i > 0)
                    {
                        if (!m_dicTab[tabName][list[0]].ContainsKey(k[i]))
                        {
                            m_dicTab[tabName][list[0]].Add(k[i], list[i]);
                        }
                        m_dicTab[tabName][list[0]][k[i]] = list[i];
                    }
                }
            }
            row++;
            be++;
        }
    }

    public static int GetDataTabLength(string name)
    {
        return 0;
    }

    public static string GetData(string tabName, string id, string field)
    {
        if (m_dicTab.ContainsKey(tabName))
        {
            if (m_dicTab[tabName].ContainsKey(id))
            {
                if (m_dicTab[tabName][id].ContainsKey(field))
                {
                    return m_dicTab[tabName][id][field];
                }
                else
                {
                    ProDebug.Logger.LogError(ProDebug.Logger.StrConcat(" field not find! tabName=", tabName, " id=", id, " field=", field));
                }
            }
            else
            {
                ProDebug.Logger.LogError(ProDebug.Logger.StrConcat("id not find! tableName=", tabName, " id=", id));
            }
        }
        else
        {
            ProDebug.Logger.LogError(ProDebug.Logger.StrConcat("tabName not find! tableName=", tabName));
        }
        return null;
    }

    public static string[] GetIds(string tabName)
    {
        if (!m_dicTab.ContainsKey(tabName))
        {
            return null;
        }
        int length = m_dicTab[tabName].Keys.Count;
        string[] ids = new string[length];
        Dictionary<string, Dictionary<string, string>>.Enumerator iter = m_dicTab[tabName].GetEnumerator();
        int count = 0;
        while (iter.MoveNext())
        {
            string key = iter.Current.Key;
            ids[count] = key;
            count++;
        }
        return ids;
    }

    public static bool HasId(string tabName, string id)
    {
        bool has = false;
        if (m_dicTab.ContainsKey(tabName))
        {
            if (m_dicTab[tabName].ContainsKey(id))
                has = true;
        }
        return has;
    }

    public static string[] GetFields(string tabName)
    {
        string[] fieldArr = new string[20];
        if (m_dicTab.ContainsKey(tabName))
        {
            Dictionary<string, Dictionary<string, string>> dic = m_dicTab[tabName];
            foreach (var kv in dic)
            {
                fieldArr = new string[kv.Value.Keys.Count];
                int index = 0;
                foreach (string key in kv.Value.Keys)
                {
                    fieldArr[index] = key;
                    ++index;
                }
                break;
            }
        }

        return fieldArr;
    }

    public static bool HasField(string tabName, string field)
    {
        bool has = false;
        if (m_dicTab.ContainsKey(tabName))
        {
            Dictionary <string, Dictionary<string, string>> dic = m_dicTab[tabName];
            foreach(var kv in dic)
            {
                if (kv.Value.ContainsKey(field))
                {
                    has = true;
                }
                break;
            }
        }
        return has;
    }
    #endregion

    #region Data

    /// <summary>
    /// key : 表数据名称
    /// TableData 
    /// </summary>
    private static Dictionary<string, Dictionary<string, Dictionary<string, string>>> m_dicTab = new Dictionary<string, Dictionary<string, Dictionary<string, string>>>();

    #endregion

}
