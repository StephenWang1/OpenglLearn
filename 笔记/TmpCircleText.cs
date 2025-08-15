using System;
using System.Collections;
using System.Collections.Generic;
using Framework.UIComponents.Text;
using TMPro;
using UnityEngine;

public class TmpCircleText : MonoBehaviour
{
    
    public int radius = 100;
    public float spaceCoff = 1f;
    public TextMeshProUGUI textMeshPro;
    private int _radius;
    private float _spaceCoff ;
    private Mesh mesh;
    private Vector3[] vertices;
    void Awake()
    {
        textMeshPro = GetComponent<UIText>();
        mesh = textMeshPro.mesh;
        vertices = mesh.vertices;

    }
    void Update()
    {
        if (_radius != radius || _spaceCoff != spaceCoff)
        {
            _radius = radius;
            _spaceCoff = spaceCoff;
            ApplyCurve();
        }
    }

    void ApplyCurve()
    {
        var textInfo = textMeshPro.textInfo;
        var vector3s= new Vector3[vertices.Length];
        Array.Copy(vertices, 0, vector3s, 0, vertices.Length);
        for (int i = 0; i < textInfo.characterCount; i++)
        {
            var characterInfo = textInfo.characterInfo[i];
            if (!characterInfo.isVisible) continue;

            int vertexIndex = characterInfo.vertexIndex;

            Vector3[] characterVertices = {
                vertices[vertexIndex],
                vertices[vertexIndex + 1],
                vertices[vertexIndex + 2],
                vertices[vertexIndex + 3]
            };
            
            var lb = characterVertices[0];
            var lt = characterVertices[ 1];
            var rt = characterVertices[ 2];
            var rb = characterVertices[ 3];
            Vector3 center = Vector3.Lerp(lb, rt, 0.5f);
            Matrix4x4 move = Matrix4x4.TRS(center * -1, Quaternion.identity, Vector3.one);
            float rad = Mathf.PI / 2 - center.x * spaceCoff / radius;
            Vector3 pos = new Vector3(Mathf.Cos(rad), Mathf.Sin(rad), 0) * radius;
            Quaternion rotation = Quaternion.Euler(0, 0, rad * 180 / Mathf.PI - 90);
            Matrix4x4 rotate = Matrix4x4.TRS(Vector3.zero, rotation, Vector3.one);
            Matrix4x4 place = Matrix4x4.TRS(pos, Quaternion.identity, Vector3.one);
            Matrix4x4 transform = place * rotate * move;

            lb = transform.MultiplyPoint(lb);
            lt = transform.MultiplyPoint(lt);
            rt = transform.MultiplyPoint(rt);
            rb = transform.MultiplyPoint(rb);
            lb.y = lb.y - radius + center.y;
            lt.y = lt.y - radius + center.y;
            rt.y = rt.y - radius + center.y;
            rb.y = rb.y - radius + center.y;
            
            
            vector3s[vertexIndex] =     lb;
            vector3s[vertexIndex + 1] = lt;
            vector3s[vertexIndex + 2] = rt;
            vector3s[vertexIndex + 3] = rb;
        }

        mesh.vertices = vector3s;
        textMeshPro.canvasRenderer.SetMesh(mesh);
    }
}
