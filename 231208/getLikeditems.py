def get_liked_items(self, user_id):
    liked_items = []

    hearts = self.db.child("heart").child(user_id).get()
    if hearts.val() is not None:
        for res in hearts.each():
            key_value = res.key()
            if res.val().get("interested") == "Y":
                liked_item_details = self.get_item_by_name(key_value)
                liked_item = {
                    'name': key_value,
                    'details': liked_item_details
                }
                liked_items.append(liked_item)

    return liked_items