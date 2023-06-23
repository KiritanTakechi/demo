<template>
  <div class="demo-app">
    <el-container>
      <el-aside width="auto">

        <el-menu default-active="0" class="demo-app__navbar--menu">
          <el-menu-item index="0" @click.native="goTo('/')">
            <span>README</span>
          </el-menu-item>
          <el-scrollbar height="calc(100vmin - 48px)" always="true">
            <el-menu-item index="1" @click.native="goTo('/prim')">
              <span>最小生成树Prim算法</span>
            </el-menu-item>
            <el-menu-item index="2" @click.native="goTo('/floyd')">
              <span>最短路径Floyd算法</span>
            </el-menu-item>
            <el-menu-item index="3" @click.native="goTo('/dijkstra')">
              <span>最短路径Dijkstra算法</span>
            </el-menu-item>
            <el-menu-item index="4" @click.native="goTo('/cpm')">
              <span>关键路径</span>
            </el-menu-item>
            <el-menu-item index="5" @click.native="goTo('/mst')">
              <span>最小生成树</span>
            </el-menu-item>
            <el-menu-item index="6" @click.native="goTo('/bt')">
              <span>二叉树及其遍历</span>
            </el-menu-item>
            <el-menu-item index="7" @click.native="goTo('/hash')">
              <span>散列表查找</span>
            </el-menu-item>
            <el-menu-item index="8" @click.native="goTo('/merge-sort')">
              <span>归并排序</span>
            </el-menu-item>
            <el-menu-item index="9" @click.native="goTo('/radix-sort')">
              <span>基数排序</span>
            </el-menu-item>
            <el-menu-item index="10" @click.native="goTo('/shell-sort')">
              <span>希尔排序</span>
            </el-menu-item>
            <el-menu-item index="11" @click.native="goTo('/huffman-tree')">
              <span>哈夫曼树</span>
            </el-menu-item>
            <el-menu-item index="12" @click.native="goTo('/avl')">
              <span>平衡二叉树</span>
            </el-menu-item>
            <el-menu-item index="13" @click.native="goTo('/topological-sort')">
              <span>拓扑排序</span>
            </el-menu-item>
            <el-menu-item index="14" @click.native="goTo('/heap-sort')">
              <span>堆排序</span>
            </el-menu-item>
            <el-menu-item index="15" @click.native="goTo('/quick-sort')">
              <span>快速排序</span>
            </el-menu-item>
          </el-scrollbar>
        </el-menu>
      </el-aside>
      <el-main>
        <el-scrollbar height="calc(100vmin - 48px)">
          <router-view></router-view>
        </el-scrollbar>
      </el-main>
    </el-container>
  </div>
</template>

<script setup lang="ts">
import { RouteLocationRaw } from 'vue-router';
import router from './router';

const goTo = (path: RouteLocationRaw) => {
  router.push(path)
}
</script>

<style scoped></style>
