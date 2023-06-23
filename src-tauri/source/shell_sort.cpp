void ShellInsert(SqList L, int dk)
{
    for (int i = dk + 1; i <= L.Length; i++)
    {
        if (L.elem[i] < L.elem[i - dk])
        {
            L.elem[0] = L.elem[i - dk];
            L.elem[i - dk] = L.elem[i];
            L.elem[i] = L.elem[0];
            i = dk + 1;
        }
    }
}