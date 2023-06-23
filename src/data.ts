type Member = {
    id: string;
    name: string;
    subject_1: string;
    subject_2: string;
    subject_3: string;
};

const groupList: Member[] = [
    {
            id: '20214101',
            name: '张祎莹',
            subject_1: '最短路径Dijkstra算法',
            subject_2: '归并排序',
            subject_3: '堆排序',
    },
    {
            id: '20214097',
            name: '付梦涵',
            subject_1: '最短路径Floyd算法',
            subject_2: '散列表查找',
            subject_3: '平衡二叉树',
    },
    {
            id: '20214099',
            name: '张珊',
            subject_1: '最小生成树Prim算法',
            subject_2: '希尔排序',
            subject_3: '哈夫曼树',
    },
    {
            id: '20214098',
            name: '马诺',
            subject_1: '关键路径',
            subject_2: '基数排序',
            subject_3: '快速排序',
    },
    {
            id: '20214072',
            name: '李延峰',
            subject_1: '最小生成树',
            subject_2: '二叉树及其遍历',
            subject_3: '拓扑排序',
    },
];

export default groupList;