import { createRouter, createWebHistory, createWebHashHistory, createMemoryHistory, RouteRecordRaw } from 'vue-router'

const routes: Array<RouteRecordRaw> = [
    {
        path: '/',
        name: "Readme",
        component: () => import('./components/Readme.vue')
    },
    {
        path: '/prim',
        name: "Prim",
        component: () => import('./components/Prim.vue')
    },
    {
        path: '/floyd',
        name: "Floyd",
        component: () => import('./components/Floyd.vue')
    },
    {
        path: '/dijkstra',
        name: "Dijkstra",
        component: () => import('./components/Dijkstra.vue')
    },
    {
        path: '/cpm',
        name: "CPM",
        component: () => import('./components/CPM.vue')
    },
    {
        path: '/mst',
        name: "MST",
        component: () => import('./components/MST.vue')
    },
    {
        path: '/bt',
        name: "BT",
        component: () => import('./components/BT.vue')
    },
    {
        path: '/hash',
        name: "Hash",
        component: () => import('./components/Hash.vue')
    },
    {
        path: '/merge-sort',
        name: "MergeSort",
        component: () => import('./components/MergeSort.vue')
    },
    {
        path: '/radix-sort',
        name: "RadixSort",
        component: () => import('./components/RadixSort.vue')
    },
    {
        path: '/shell-sort',
        name: "ShellSort",
        component: () => import('./components/ShellSort.vue')
    },
    {
        path: '/huffman-tree',
        name: "HuffmanTree",
        component: () => import('./components/HuffmanTree.vue')
    },
    {
        path: '/avl',
        name: "AVL",
        component: () => import('./components/AVL.vue')
    },
    {
        path: '/topological-sort',
        name: "TopologicalSort",
        component: () => import('./components/TopologicalSort.vue')
    },
    {
        path: '/heap-sort',
        name: "HeapSort",
        component: () => import('./components/HeapSort.vue')
    },
    {
        path: '/quick-sort',
        name: "QuickSort",
        component: () => import('./components/QuickSort.vue')
    },

]



const router = createRouter({
    history: createWebHistory(),
    routes
})

export default router