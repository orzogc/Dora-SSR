static void content_set_search_paths(int64_t var) {
	SharedContent.setSearchPaths(from_str_vec(var));
}
static int64_t content_get_search_paths() {
	return to_vec(SharedContent.getSearchPaths());
}
static int64_t content_get_asset_path() {
	return str_retain(SharedContent.getAssetPath());
}
static int64_t content_get_writable_path() {
	return str_retain(SharedContent.getWritablePath());
}
static void content_save(int64_t filename, int64_t content) {
	SharedContent.save(*str_from(filename), *str_from(content));
}
static int32_t content_exist(int64_t filename) {
	return SharedContent.exist(*str_from(filename)) ? 1 : 0;
}
static int32_t content_mkdir(int64_t path) {
	return SharedContent.createFolder(*str_from(path)) ? 1 : 0;
}
static int32_t content_isdir(int64_t path) {
	return SharedContent.isFolder(*str_from(path)) ? 1 : 0;
}
static int32_t content_remove(int64_t path) {
	return SharedContent.remove(*str_from(path)) ? 1 : 0;
}
static int64_t content_get_full_path(int64_t filename) {
	return str_retain(SharedContent.getFullPath(*str_from(filename)));
}
static void content_add_search_path(int64_t path) {
	SharedContent.addSearchPath(*str_from(path));
}
static void content_insert_search_path(int32_t index, int64_t path) {
	SharedContent.insertSearchPath(s_cast<int>(index), *str_from(path));
}
static void content_remove_search_path(int64_t path) {
	SharedContent.removeSearchPath(*str_from(path));
}
static void content_clear_path_cache() {
	SharedContent.clearPathCache();
}
static int64_t content_get_dirs(int64_t path) {
	return to_vec(SharedContent.getDirs(*str_from(path)));
}
static int64_t content_get_files(int64_t path) {
	return to_vec(SharedContent.getFiles(*str_from(path)));
}
static int64_t content_get_all_files(int64_t path) {
	return to_vec(SharedContent.getAllFiles(*str_from(path)));
}
static void content_load_async(int64_t filename, int32_t func, int64_t stack) {
	std::shared_ptr<void> deref(nullptr, [func](auto) {
		SharedWasmRuntime.deref(func);
	});
	auto args = r_cast<CallStack*>(stack);
	SharedContent.loadAsync(*str_from(filename), [func, args, deref](String content) {
		args->clear();
		args->push(content);
		SharedWasmRuntime.invoke(func);
	});
}
static void content_copy_async(int64_t src_file, int64_t target_file, int32_t func) {
	std::shared_ptr<void> deref(nullptr, [func](auto) {
		SharedWasmRuntime.deref(func);
	});
	SharedContent.copyAsync(*str_from(src_file), *str_from(target_file), [func, deref]() {
		SharedWasmRuntime.invoke(func);
	});
}
static void content_save_async(int64_t filename, int64_t content, int32_t func) {
	std::shared_ptr<void> deref(nullptr, [func](auto) {
		SharedWasmRuntime.deref(func);
	});
	SharedContent.saveAsync(*str_from(filename), *str_from(content), [func, deref]() {
		SharedWasmRuntime.invoke(func);
	});
}
static void linkContent(wasm3::module& mod) {
	mod.link_optional("*", "content_set_search_paths", content_set_search_paths);
	mod.link_optional("*", "content_get_search_paths", content_get_search_paths);
	mod.link_optional("*", "content_get_asset_path", content_get_asset_path);
	mod.link_optional("*", "content_get_writable_path", content_get_writable_path);
	mod.link_optional("*", "content_save", content_save);
	mod.link_optional("*", "content_exist", content_exist);
	mod.link_optional("*", "content_mkdir", content_mkdir);
	mod.link_optional("*", "content_isdir", content_isdir);
	mod.link_optional("*", "content_remove", content_remove);
	mod.link_optional("*", "content_get_full_path", content_get_full_path);
	mod.link_optional("*", "content_add_search_path", content_add_search_path);
	mod.link_optional("*", "content_insert_search_path", content_insert_search_path);
	mod.link_optional("*", "content_remove_search_path", content_remove_search_path);
	mod.link_optional("*", "content_clear_path_cache", content_clear_path_cache);
	mod.link_optional("*", "content_get_dirs", content_get_dirs);
	mod.link_optional("*", "content_get_files", content_get_files);
	mod.link_optional("*", "content_get_all_files", content_get_all_files);
	mod.link_optional("*", "content_load_async", content_load_async);
	mod.link_optional("*", "content_copy_async", content_copy_async);
	mod.link_optional("*", "content_save_async", content_save_async);
}