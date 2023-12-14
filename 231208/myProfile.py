@application.route('/myProfile')
def myProfile():
    user_id = session.get('id')
    user = DB.get_user_by_id(user_id)  # DB에서 사용자 정보를 가져오는 함수
    
    if user:
        # 해당 사용자의 리뷰 정보 가져오기
        buyer_reviews = DB.get_buyer_reviews_by_user_id(user_id)
        
        # 리뷰 정보에서 평점만 추출하여 숫자로 변환하여 리스트로 저장
        ratings = [float(review['rating']) for review in buyer_reviews if 'rating' in review]
        
        # 리뷰가 있는 경우에만 평균 계산
        average_rating = sum(ratings) / len(ratings) if ratings else 0
    else:
        average_rating = 0

    return render_template('myProfile.html', average_rating=average_rating, session=session)