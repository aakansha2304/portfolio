// Add new recommendation
document.getElementById('recommendation-form').addEventListener('submit', function (e) {
    e.preventDefault(); // Prevent form submission
  
    // Get the recommendation text
    const recommendation = document.querySelector('#recommendation-form textarea').value;
  
    // Check if the recommendation is not empty
    if (recommendation.trim() === "") {
      alert("Please enter a recommendation before submitting.");
      return;
    }
  
    // Get the recommendations container
    const recommendationsContainer = document.querySelector('.recommendations-container');
  
    // Create a new paragraph element for the recommendation
    const newRecommendation = document.createElement('p');
    newRecommendation.textContent = "${recommendation}" - NewUser;
  
    // Append the new recommendation to the container
    recommendationsContainer.appendChild(newRecommendation);
  
    // Show a popup message
    alert('Thank you for submitting a recommendation!');
  
    // Clear the textarea
    document.querySelector('#recommendation-form textarea').value = '';
  });