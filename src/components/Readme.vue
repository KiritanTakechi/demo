<template>
        <el-table :data="groupList" style="width: 100%">
                <el-table-column prop="id" label="学号" />
                <el-table-column prop="name" label="姓名" />
                <el-table-column prop="subject_1" label="题目 1" />
                <el-table-column prop="subject_2" label="题目 2" />
                <el-table-column prop="subject_3" label="题目 3" />
        </el-table>
</template>
    
<script setup lang='ts'>
import groupList from '../data'

</script>
    
<style></style>